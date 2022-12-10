#FDS Group B Assignment 14

'''

Write a Python program to store first year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.

'''

n=int(input("Enter the total no. of students:"))
marks=[]

for i in range(n):
    marks.append(float(input("Enter the marks of the students:")))
print("Marks of students in unsorted list:",marks)

def selection_sort():
    for i in range(len(marks)):
        for j in range(i,len(marks)):
            if(marks[i]>marks[j]):
                marks[i],marks[j]=marks[j],marks[i]
            else:
                pass
    return marks


def bubble_sort():
    for i in range(len(marks)-1):
        for j in range(0,len(marks)-i-1):
            if(marks[j]>marks[j+1]):
                marks[i],marks[j]=marks[j],marks[i]

            else:
                pass
    return marks


def calling():

    while(True):
        print("----------------------------Menu-------------------------------")
        print("1.Marks list using Selection Sort\n2.Marks list using Bubble Sort\n3.Top 5 scores in the class\n4.Exit")
        ch=int(input("Enter your choice:"))

        if ch==1:
            answer=selection_sort()
            print("Marks list sorted using selection sort:\n",answer)

        if ch==2:
            answer=bubble_sort()
            print("Marks list sorted using bubble sort:\n",answer)

        if ch==3:
            print("Top 5 scores using Bubble sort :" , marks[-5:])

        if ch>=4:
            print("You have successfully exited")
            break


calling()

