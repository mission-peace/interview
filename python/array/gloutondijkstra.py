#!/usr/bin/env python3
# -*- coding: utf-8 -*-
####################################################################################################################################################################################################################################
######################################################################################################## PRE-DEFINED IMPORTS #######################################################################################################
####################################################################################################################################################################################################################################

# Imports that are necessary for the program architecture to work properly
# Do not edit this code

import ast
import sys
import os
import queue
import time

####################################################################################################################################################################################################################################
########################################################################################################### YOUR IMPORTS ###########################################################################################################
####################################################################################################################################################################################################################################


import random
import time
import math

####################################################################################################################################################################################################################################
####################################################################################################### PRE-DEFINED CONSTANTS ######################################################################################################
####################################################################################################################################################################################################################################

# Possible characters to send to the maze application
# Any other will be ignored
# Do not edit this code

UP = 'U'
DOWN = 'D'
LEFT = 'L'
RIGHT = 'R'

####################################################################################################################################################################################################################################

# Name of your team
# It will be displayed in the maze
# You have to edit this code

TEAM_NAME = "CL ACR"

####################################################################################################################################################################################################################################
########################################################################################################## YOUR CONSTANTS ##########################################################################################################
####################################################################################################################################################################################################################################

# [YOUR CODE HERE]

####################################################################################################################################################################################################################################
########################################################################################################## YOUR VARIABLES ##########################################################################################################
####################################################################################################################################################################################################################################

# [YOUR CODE HERE]
visitedCells=[]
attemptedMoves={}
path={}
pathGlouton=[]
visitedNode=[]
locationToMove=[]
distances={}  #dictionnaire
priority=[] #list
route={}  #dictionnaire
#####################################################################################################################################################################################################################################
####################################################################################################### PRE-DEFINED FUNCTIONS ######################################################################################################
####################################################################################################################################################################################################################################

# Writes a message to the shell
# Use for debugging your program
# Channels stdout and stdin are captured to enable communication with the maze
# Do not edit this code

def debug (text) :
    
    # Writes to the stderr channel
    sys.stderr.write(str(text) + "\n")
    sys.stderr.flush()

####################################################################################################################################################################################################################################

# Reads one line of information sent by the maze application
# This function is blocking, and will wait for a line to terminate
# The received information is automatically converted to the correct type
# Do not edit this code

def readFromPipe () :
    
    # Reads from the stdin channel and returns the structure associated to the string
    try :
        text = sys.stdin.readline()
        return ast.literal_eval(text.strip())
    except :
        os._exit(-1)

####################################################################################################################################################################################################################################

# Sends the text to the maze application
# Do not edit this code

def writeToPipe (text) :
    
    # Writes to the stdout channel
    sys.stdout.write(text)
    sys.stdout.flush()

####################################################################################################################################################################################################################################

# Reads the initial maze information
# The function processes the text and returns the associated variables
# The dimensions of the maze are positive integers
# Maze map is a dictionary associating to a location its adjacent locations and the associated weights
# The preparation time gives the time during which 'initializationCode' can make computations before the game starts
# The turn time gives the time during which 'determineNextMove' can make computations before returning a decision
# Player locations are tuples (line, column)
# Coins are given as a list of locations where they appear
# A boolean indicates if the game is over
# Do not edit this code

def processInitialInformation () :
    
    # We read from the pipe
    data = readFromPipe()
    return (data['mazeWidth'], data['mazeHeight'], data['mazeMap'], data['preparationTime'], data['turnTime'], data['playerLocation'], data['opponentLocation'], data['coins'], data['gameIsOver'])

####################################################################################################################################################################################################################################

# Reads the information after each player moved
# The maze map and allowed times are no longer provided since they do not change
# Do not edit this code

def processNextInformation () :

    # We read from the pipe
    data = readFromPipe()
    return (data['playerLocation'], data['opponentLocation'], data['coins'], data['gameIsOver'])

####################################################################################################################################################################################################################################
########################################################################################################## YOUR FUNCTIONS ##########################################################################################################
####################################################################################################################################################################################################################################

# [YOUR CODE HERE]
def findValidMoves(playerlocation,mazeWidth,mazeHeight):

    locationIfGoingUp=(max(playerlocation[0]-1,0),playerlocation[1])
    locationIfGoingDown=(min(playerlocation[0]+1,mazeHeight),playerlocation[1])
    locationIfGoingLeft=(playerlocation[0],max(playerlocation[1]-1,0))
    locationIfGoingRight=(playerlocation[0],min(playerlocation[1]+1,mazeWidth))

    moves = []
    for n in [(locationIfGoingUp,UP),(locationIfGoingDown,DOWN),(locationIfGoingLeft,LEFT),(locationIfGoingRight,RIGHT)]:
       if n[0] not in visitedCells and n[1] not in attemptedMoves[playerlocation]:
           moves.append(n[1])
    return moves

def breadthFirstSearch(graph,sourceNode):

    global visitedNode,path ########################
    ourQueue=queue.Queue()
    ourQueue.put(sourceNode)
    visitedNode.append(sourceNode)
    while not ourQueue.empty():
         currentNode=ourQueue.get()
         for (neighbor,power) in mazeMap[currentNode]:
             if neighbor not in visitedNode:
                visitedNode.append(neighbor)
                ourQueue.put(neighbor)
                path[neighbor]=path[currentNode]+[neighbor]
   # debug(str(path))

def transferLocationToMove(Path):
 
    #breadthFirstSearch(graph,sourceNode)
    (xLast,yLast)=Path[0]
    #debug(str(xLast)+"++"+str(yLast))
    #debug("path="+str(Path)+'\n')
    for node in Path:
        #debug(str(xNow)+"++"+str(yNow))
        xNow=node[0]
        yNow=node[1]
        #debug(str(node)+"  "+str(xNow)+"  "+str(yNow))
        horizontal=yNow-yLast
        vertical=xNow-xLast
        xLast=xNow
        yLast=yNow
        if horizontal!=0:
           if horizontal==1:
              locationToMove.append(RIGHT)
           else:
              locationToMove.append(LEFT)
        else:
           if vertical==1:
              locationToMove.append(DOWN)
           elif vertical==-1:
              locationToMove.append(UP)
    #debug(str(locationToMove))

def putInPriority(priority,node,distance):
    for i in range(len(priority)):
        if priority[i][0]==node:
           return
    priority.append([node,distance])

def getOutPriority(priority):           #get out the node with min distance 
    nodeIndex=0                         
    nodeMin=priority[nodeIndex][0]      #coordonn茅e
    distanceMin=priority[nodeIndex][1]  #distance
    for i in range(len(priority)):
        if priority[i][1]<distanceMin:
           distanceMin=priority[i][1]
           nodeMin=priority[i][0]
           nodeIndex=i
    del priority[nodeIndex]
    return [nodeMin,distanceMin]

def replace(priority,node,distance):
    for i in range(len(priority)):
        if priority[i][0]==node:
           priority[i][1]=distance
           
def dijkstra(startNode,graph):
    global distances,priority,visitedNode,route
    priority=[]
    visitedNode=[]
    for l in range (mazeHeight):
       for c in range(mazeWidth):
           route[(l,c)]=(l,c)                         #initiation de routage
    for l in range (mazeHeight):
       for c in range(mazeWidth):
           distances[(l,c)]=sys.maxsize               #initiation de distance
    distances[startNode]=0
    putInPriority(priority,startNode,distances[startNode])
    while  priority!=[]:
          (currentNode,distance)=getOutPriority(priority)
          visitedNode.append(currentNode)
          for (neighbor,distanceToNeighbor) in graph[currentNode]:
              if neighbor not in visitedNode:
                 putInPriority(priority,neighbor,distances[neighbor])
                 distancePassCN=distance+distanceToNeighbor
                 if distances[neighbor]>distancePassCN:
                    distances[neighbor]=distancePassCN
                    replace(priority,neighbor,distancePassCN)
                    route[neighbor]=currentNode

def routeToPath(route):
    global path
    path={}
    for l in range (mazeHeight):
       for c in range(mazeWidth):
          node=(l,c)
          tempNode=node
          path[node]=[node]
          while route[tempNode]!=tempNode:
                path[node]=path[node]+[route[tempNode]]
                tempNode=route[tempNode]
          #path[node]=path[node]+[route[tempNode]]
          path[node].reverse()
    #debug("RouteToPath"+str(path))

def glouton(graph):
    global pathGlouton
    restant=coins
    start=playerLocation
    Ordre=[start]
    while restant!=[]:
         dijkstra(start,graph)
         routeToPath(route)
         distMin=sys.maxsize
         nodeMin=[]
         #debug("restant="+str(restant))
         for node in restant:
             if distances[node]<distMin:
                #debug("dist="+str(distances[node]))
                distMin=distances[node]
                nodeMin=[node]
         Ordre=Ordre+nodeMin
         #debug("node="+str(nodeMin))
         pathGlouton=pathGlouton+path[nodeMin[0]]
         start=nodeMin[0]
         restant.remove(nodeMin[0])
    #debug("Ordre="+str(Ordre)+"\n")
    transferLocationToMove(pathGlouton)
    
              
####################################################################################################################################################################################################################################

# This is where you should write your code to do things during the initialization delay
# This function should not return anything, but should be used for a short preprocessing
# This function takes as parameters the dimensions and map of the maze, the time it is allowed for computing, the players locations in the maze and the remaining coins locations
# Make sure to have a safety margin for the time to include processing times (communication etc.)

def initializationCode (mazeWidth, mazeHeight, mazeMap, timeAllowed, playerLocation, opponentLocation, coins) :
    
    # [YOUR CODE HERE]
    global attemptedMoves
    for l in range (mazeHeight):
       for c in range(mazeWidth):
           attemptedMoves[(l,c)]=[]
     
    # [EXAMPLE] Prints the information to the shell
    debug("\n" + "mazeWidth = " + str(mazeWidth) + "\n"
               + "mazeHeight = " + str(mazeHeight) + "\n"
               #+ "mazeMap = " + str(mazeMap) + "\n"
               + "timeAllowed = " + str(timeAllowed) + "\n"
               + "playerLocation = " + str(playerLocation) + "\n"
               + "opponentLocation = " + str(opponentLocation) + "\n"
               + "coins = " + str(coins) + "\n")
    

####################################################################################################################################################################################################################################

# This is where you should write your code to determine the next direction
# This function should return one of the directions defined in the CONSTANTS section
# This function takes as parameters the dimensions and map of the maze, the time it is allowed for computing, the players locations in the maze and the remaining coins locations
# Make sure to have a safety margin for the time to include processing times (communication etc.)

def determineNextMove (mazeWidth, mazeHeight, mazeMap, timeAllowed, playerLocation, opponentLocation, coins) :
    
    # [YOUR CODE HERE]
    action=locationToMove[0]
    del locationToMove[0]
    return action
    # [EXAMPLE] Goes up all the time
    

####################################################################################################################################################################################################################################
############################################################################################################# MAIN LOOP ############################################################################################################
####################################################################################################################################################################################################################################

# This is the entry point when executing this file
# We first send the name of the team to the maze
# The first message we receive from the maze includes its dimensions and map, the times allowed to the various steps, and the players and coins locations
# Then, at every loop iteration, we get the maze status and determine a move
# Do not edit this code

if __name__ == "__main__" :
    a=time.clock()
    # We send the team name
    writeToPipe(TEAM_NAME + "\n")
    
    # We process the initial information and have a delay to compute things using it
    (mazeWidth, mazeHeight, mazeMap, preparationTime, turnTime, playerLocation, opponentLocation, coins, gameIsOver) = processInitialInformation()
    initializationCode(mazeWidth, mazeHeight, mazeMap, preparationTime, playerLocation, opponentLocation, coins)
    a=time.clock()
    glouton(mazeMap)
    debug(str(time.clock()-a))
    #debug(str(locationToMove))
    #debug("dis="+str(distances))
    # We decide how to move and wait for the next step
    while not gameIsOver :
        (playerLocation, opponentLocation, coins, gameIsOver) = processNextInformation()
        #debug(str(len(coins)))
        if gameIsOver :
            break
        nextMove = determineNextMove(mazeWidth, mazeHeight, mazeMap, turnTime, playerLocation, opponentLocation, coins)
        writeToPipe(nextMove)

####################################################################################################################################################################################################################################
####################################################################################################################################################################################################################################
