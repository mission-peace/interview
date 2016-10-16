#include <iostream>
#include <queue>
using namespace std;


int r,c;
char pMatrix[22][22];
int S[2];
int B[2];
int T[2];

int r_4dir[4]={-1,0,1,0};
int c_4dir[4]={0,1,0,-1};
char _walk_dir[4]={'n','e','s','w'};
char _push_dir[4]={'N','E','S','W'};

bool check_box_position(int boxr,int boxc)

{

    int curR=boxr+r_4dir[3];
	int curC=boxc+c_4dir[3];

    bool past=pMatrix[curR][curC]=='#';

    for (int i=0;i<4;i++)

    {

        curR=boxr+r_4dir;
		curC=boxc+c_4dir;

        if (past&&pMatrix[curR][curC]=='#')

            return false;

        past=pMatrix[curR][curC]=='#';

    }

    return true;

}



bool bfs_person(int fromR,int fromC,int toR,int toC,char* path,int& pathLen,int curBoxR,int curBoxC)

{

    if (fromR==toR&&fromC==toC)

    {

        pathLen=0;

        return true;

    }

    char tmp=pMatrix[curBoxR][curBoxC];pMatrix[curBoxR][curBoxC]='#';

    queue<int> Q;

    Q.push(fromR);Q.push(fromC);

    char pTmpMatrix[21][21]={0};

    char pPath_R[21][21]={0};

    char pPath_C[21][21]={0};

    pTmpMatrix[fromR][fromC]=1;

    while (!Q.empty())

    {

        int curR=Q.front();Q.pop();

        int curC=Q.front();Q.pop();

        int i;

        for (i=0;i<4;i++)

        {

            int nexR=curR+r_4dir;

            int nexC=curC+c_4dir;

            if (pMatrix[nexR][nexC]!='#'&&!pTmpMatrix[nexR][nexC])

            {

                pTmpMatrix[nexR][nexC]=_walk_dir;

                pPath_R[nexR][nexC]=curR;pPath_C[nexR][nexC]=curC;

                if (nexR==toR&&nexC==toC)

                {

                    pMatrix[curBoxR][curBoxC]=tmp;

                    pathLen=0;

                    while (1!=pTmpMatrix[nexR][nexC])

                    {

                        path[pathLen++]=pTmpMatrix[nexR][nexC];

                        int tmpR=pPath_R[nexR][nexC],tmpC=pPath_C[nexR][nexC];

                        nexR=tmpR;nexC=tmpC;

                    }

                    return true;

                }

                Q.push(nexR);Q.push(nexC);

            }

        }

    }

    pMatrix[curBoxR][curBoxC]=tmp;

    return false;

}

void PrintPath(char (*pBoxPath)[21],char (*pPerPath)[21][401],short (*pPathLen_Walk)[21],char (*pPath_R)[21],char (*pPath_C)



[21])

{

    char path[160001]={0};

    int pathLen=0;

    int curR=T[0],curC=T[1];

    while (pBoxPath[curR][curC]!=1)

    {

        path[pathLen++]=pBoxPath[curR][curC];

        memcpy(path+pathLen,pPerPath[curR][curC],pPathLen_Walk[curR][curC]);

        pathLen+=pPathLen_Walk[curR][curC];

      

        int tmpR=pPath_R[curR][curC],tmpC=pPath_C[curR][curC];

        curR=tmpR;curC=tmpC;

    }

    pathLen--;

    while (pathLen>=0)

    {

        printf("%c",path[pathLen--]);

    }

    printf("\n\n");

}

bool bfs_box()

{

    char pTmpMatrix[21][21]={0};

    short pathLen_Walk[21][21]={0};

    char pPath_Walk[21][21][401]={0};

    char pMinPushCount[21][21]={0};

    char pMinCount[21][21]={0};

    char pPath_R[21][21]={0};

    char pPath_C[21][21]={0};

    queue<int> Q;

    bool flag=false;

    Q.push(B[0]);Q.push(B[1]);Q.push(S[0]);Q.push(S[1]);Q.push(0);Q.push(0);

    pTmpMatrix[B[0]][B[1]]=1;

    while (!Q.empty())

    {

        int curBoxR=Q.front();Q.pop();

        int curBoxC=Q.front();Q.pop();

        int curPerR=Q.front();Q.pop();

        int curPerC=Q.front();Q.pop();

        int curPushCount=Q.front();Q.pop();

        int curCount=Q.front();Q.pop();

        if (flag&&pMinPushCount[T[0]][T[1]]<=curPushCount)

        {

            break;

        }

        int i;

        for (i=0;i<4;i++)

        {

            int nexBoxR=curBoxR+r_4dir;

            int nexBoxC=curBoxC+c_4dir;

            int needPerR=curBoxR-r_4dir;

            int needPerC=curBoxC-c_4dir;

            char path[400]={0};

            int pathLen;

            if(pMatrix[nexBoxR][nexBoxC]!='#'&&pMatrix[needPerR][needPerC]!='#'&&

                (nexBoxR==T[0]&&nexBoxC==T[1]||check_box_position(nexBoxR,nexBoxC))&&

                bfs_person(curPerR,curPerC,needPerR,needPerC,path,pathLen,curBoxR,curBoxC))

            {

                int tmpPushCount=curPushCount+1;

                int tmpCount=curCount+1+pathLen;

                if(pTmpMatrix[nexBoxR][nexBoxC])

                    if (pMinPushCount[nexBoxR][nexBoxC]<tmpPushCount||

                        (pMinPushCount[nexBoxR][nexBoxC]==tmpPushCount&&pMinCount[nexBoxR][nexBoxC]



<=tmpCount))

                    {

                        continue;

                    }

                pTmpMatrix[nexBoxR][nexBoxC]=_push_dir;

                pPath_R[nexBoxR][nexBoxC]=curBoxR;

                pPath_C[nexBoxR][nexBoxC]=curBoxC;

                pMinPushCount[nexBoxR][nexBoxC]=tmpPushCount;

                pMinCount[nexBoxR][nexBoxC]=tmpCount;

                pathLen_Walk[nexBoxR][nexBoxC]=pathLen;

                memcpy(pPath_Walk[nexBoxR][nexBoxC],path,pathLen);

                if (nexBoxR==T[0]&&nexBoxC==T[1])

                {

                    flag=true;

                }

                else

                {

                    Q.push(nexBoxR);Q.push(nexBoxC);Q.push(curBoxR);Q.push(curBoxC);

                    Q.push(tmpPushCount);Q.push(tmpCount);

                }

            }

        }

    }

    if (!flag)

        printf("Impossible.\n\n");

    else

        PrintPath(pTmpMatrix,pPath_Walk,pathLen_Walk,pPath_R,pPath_C);

    return flag;

}



int main()

{

    int index=0;

    while(EOF!=scanf("%d%d",&r,&c),r&&c)

    {

        index++;

        memset(pMatrix,'#',sizeof(pMatrix));

        printf("Maze #%d\n",index);

        int row,column;

        for (row=1;row<=r;row++)

            for (column=1;column<=c;column++)

            {

                cin>>pMatrix[row][column];

                switch(pMatrix[row][column])

                {

                case 'S':

                    S[0]=row;S[1]=column;

                    break;

                case 'B':

                    B[0]=row;B[1]=column;

                    break;

                case 'T':

                    T[0]=row;T[1]=column;

                    break;

                }

            }

            if (!check_box_position(B[0],B[1]))

                printf("Impossible.\n\n");  

            else bfs_box();

    }

    return 0;

}
