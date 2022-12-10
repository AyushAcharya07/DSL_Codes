# DSL Assignment B11 B

'''
Write a Python program to store roll numbers of student array who attended training
program in sorted order. Write function for searching whether particular student
attended training program or not, using Binary search and Fibonacci search

'''

t=int(input("Enter the total no. of students attended the session:"))
student_list=[]
for i in range(t):
    student_list.append(int(input("Enter the roll nos. of present students:")))

student_list.sort()

check=int(input("Enter the roll no. you want to search:"))

start=0

def binary_search(student_list,check,start,t):

    if start>t:
        return -1

    mid=(start+t)//2

    if check==student_list[mid]:
        return mid

    if check<student_list[mid]:
        return binary_search(student_list,check,start,mid-1)

    else:
        return binary_search(student_list,check,mid+1,t)

def fibonacci_search(a,target):
    n=len(a)
    fibn_2=0
    fibn_1=1
    fibn=fibn_1+fibn_2
    while(fibn<=n):
        fibn_2=fibn_1
        fibn_1=fibn
        fibn=fibn_1+fibn_2

    offset=-1
    while(fibn_1!=0):
        i=min((offset+fibn_2),n-1)
        if(target>a[i]):
            fibn=fibn_1
            fibn_1=fibn_2
            fibn_2=fibn-fibn_1
            offset=i
        elif(target<a[i]):
            fibn=fibn_2
            fibn_1=fibn_1-fibn_2
            fibn_2=fibn-fibn_1
        elif(target==a[i]):
            print("present")
            break
    else:
        print("Absent")


def main():
    while(True):
        print("--------------------Menu-------------------------")
        print("To search using Binary search\n2.To search using Fibonacci Search\n3.Exit")
        ch=int(input("Enter your choice:"))

        if ch==1:
            answer = binary_search(student_list, check, start, t)
            if answer == -1:
                print("The entered roll no. did not attend the training program.")
            else:
                print("The entered roll no. has attended the training program.")

        if ch==2:
            fibonacci_search(student_list,check)

        if ch>=3:
            print("You have successfully exited")
            break

main()