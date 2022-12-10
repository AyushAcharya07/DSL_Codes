'''WAP to store the marks scored in subject FDS by n students in the class.Write function to compute the following:
 1. Average score of the class
 2. Highest and Lowest score of the class
 3. Count of students who were absent for the test
 4. Display marks with highest frequency'''

n=int(input('Enter the total no. of students:'))
marks=[]
for i in range(n):
    marks.append(int(input('Enter the marks of the students:'))) #Enter marks as '-1' for absent students
while(True):
    print('1.Average score of the class\n2.Highest and Lowest score of the class\n3.Count of students who were absent for the test\n4.Display marks with highest frequency')
    ch=int(input('Enter your choice:'))

#Case 1: Average score of the class
    if ch==1:

        def average_marks():
            sum=0
            for i in range(n):
                sum+=marks[i]
            avg=sum/n
            print('Average score of the class is:',avg)

        average_marks()

#Case 2: Highest & Lowest score of the class
    if ch==2:

        def max_min():
            maxmarks=0
            minmarks=marks[0]
            for i in marks:
                if (i==0 or i>maxmarks):
                    maxmarks=i
            print('Highest score in the class:',maxmarks)



            for j in range(1,len(marks)):
                if (marks[j]<minmarks and marks[j]!=-1):
                    minmarks=marks[j]
            print('Lowest score of the class:',minmarks)
        max_min()

# Case 3: Count of students who were absent for the test
    if ch==3:

        def absent():
            absent_students=[]
            l=0
            for m in marks:
                if m==-1:
                    absent_students.append(m)
                    l=len(absent_students)
            print('No. of students absent for test:',l)

        absent()

# Case 4 : Display marks with highest frequency
    if ch==4:
        def frequency():
            freq=0
            freq_marks=0
            for i in range (len(marks)):
                count=0
                if (marks[i]!= -1):
                    for j in range (len(marks)):
                        if (marks[i]==marks[j]):
                            count+=1
                if (freq < count):
                    freq_marks= marks[i]
                    freq=count

            print("Marks with highest frequency is :%d:- (%d) times" %(freq_marks,freq))
        frequency()

    if ch>=5:
        print('Sorry! Wrong choice entered.\nPlease try again')
        break
