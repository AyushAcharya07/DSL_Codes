# FDS Assignment B16

'''

Write a Python program to store first year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using quick sort
and display top five scores.

'''

n=int(input("Enter total no. of students : "))
marks=[]

for i in range(n):
    marks.append(float(input("Enter the marks of the students : ")))


def partition(array,low,high):

    pivot=array[high]
    i=low-1

    for j in range(low,high):

        if array[j]<=pivot:
            i+=1

            array[i],array[j]=array[j],array[i]

    array[i+1],array[high]=array[high],array[i+1]

    return i+1

def quick_sort(array,low,high):

    if (low<high):
        part=partition(array,low,high)

        quick_sort(array,low,part-1)

        quick_sort(array,part+1,high)



quick_sort(marks,0,(len(marks)-1))

print("Sorted array of marks using quick sort",marks)
print("Top 5 highest scores in the class:",marks[-5:])



