# https://leetcode.com/problems/the-skyline-problem/

class BuildingPoint(object):

    def __init__(self, point, is_start, height):
        self.point = point;
        self.is_start = is_start
        self.height = height
        
    def __lt__(self, other):
        if self.point != other.point:
            return self.point < other.point
        else:
            if self.is_start:
                h1 = -self.height
            else:
                h1 = self.height

            if other.is_start:
                h2 = -other.height;
            else:
                h2 = other.height

            return h1 < h2
    
def get_skyline(buildings):

    building_points = []
    for building in buildings:
        building_points.append(BuildingPoint(building[0], True, building[2]))
        building_points.append(BuildingPoint(building[1], False, building[2]))

    building_points = sorted(building_points)

    queue = {}
    queue[0] = 1
    prev_max_height = 0
    critical_points = []
    for building_point in building_points:
        if building_point.is_start:
            if building_point.height in queue:
                queue[building_point.height] = queue[building_point.height] + 1
            else:
                queue[building_point.height] = 1
    
        else:
            if queue[building_point.height] == 1:
                del queue[building_point.height]
            else:
                queue[building_point.height] = queue[building_point.height] - 1

        current_max_height = max(queue.keys())

        if prev_max_height != current_max_height:
            critical_points.append([building_point.point, current_max_height])
            prev_max_height = current_max_height
    return critical_points

if __name__ == '__main__':
    buildings = [[0, 3, 3], [1, 5, 3], [2, 4, 3], [3, 7, 3]]
    print(get_skyline(buildings))
    
