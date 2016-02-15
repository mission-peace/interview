#Box stacking dynamic programming
#Java code https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/BoxStacking.java 

class Dimension(object):
   
    def __init__(self, height = 0, length = 0, width = 0):
        self.height = height
        self.length = length
        self.width = width

    def __lt__(self, other):
        return self.length*self.width > other.length*other.width

    def __str__(self):
        return str(self.height) + " " + str(self.length) + " " + str(self.width)
    
    @classmethod
    def create_empty(self):
        return self(0,0,0)

def create_dimension(height, side1, side2):
    d = Dimension();
    d.height = height
    if side1 > side2 :
        d.length = side1
        d.width = side2
    else:
        d.width = side1
        d.length = side2
    return d;            

def max_height(dimensions):
    all_rotations = create_all_rotations(dimensions)
    all_rotations.sort()
    T = []
    result = []
    for i in range(len(all_rotations)):
        T.append(all_rotations[i].height)
        result.append(i)

    for i in range(1, len(T)):
        for j in range(0, i):
            if(all_rotations[i].length < all_rotations[j].length
               and all_rotations[i].width < all_rotations[j].width):
                T[i] = T[j] + all_rotations[i].height;
                result[i] = j
    max_height = 0
    for m in T:
        max_height = max(m, max_height)

    return max_height

def create_all_rotations(dimensions):
    all_rotated_dimensions = []
    for dimension in dimensions:
        new_dimension = create_dimension(dimension.height, dimension.length,
                                         dimension.width)
        all_rotated_dimensions.append(new_dimension)
        new_dimension = create_dimension(dimension.length, dimension.height,
                                         dimension.width)
        all_rotated_dimensions.append(new_dimension)
        new_dimension = create_dimension(dimension.width, dimension.height,
                                         dimension.length)
        all_rotated_dimensions.append(new_dimension)
    return all_rotated_dimensions

max = max_height([Dimension(3,2,5), Dimension(1,2,4)])
print("Max height", max);

