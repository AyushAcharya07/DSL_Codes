'''
DSL Expt A3
Write a Python program to compute following computation on matrix:
a) Addition of two matrices B) Subtraction of two matrices
c) Multiplication of two matrices d) Transpose of a matrix

'''


Matrix_1=[]
Matrix_2=[]
Addn=[]
Subn=[]
Multipn=[]
print("Input for rows and columns of the matrix")
r=int(input('Enter the no. of rows:'))
c=int(input('Enter the no. of columns:'))

def read_matrix():
    m=[]
    for i in range(r):
        a=[]
        for j in range(c):
            a.append(int(input('Enter the elements for the matrix:')))
        m.append(a)
    return (m)

def display_matrix(m):
    for i in range(r):
        for j in range(c):
            print(m[i][j],end=" ")
        print()


def add_matrix(a,b):
    for i in range(len(a)):
        tadd=[]         #temporary list used for addition
        for j in range(len(a[i])):
            result_add=a[i][j]+b[i][j]
            tadd.append(result_add)
        Addn.append(tadd)
    return Addn



def sub_matrix(a,b):
    for i in range(len(a)):
        tsub=[]
        for j in range(len(a[i])):
            result_sub=a[i][j]-b[i][j]
            tsub.append(result_sub)
        Subn.append(tsub)
    return Subn


def multiply_matrix(mat1,mat2):
    ans=[]
    if (len(mat1) != len(mat2[0])):
        print("Multiplication cannot be performed!!")
    for i in range(len(mat1)):
        a=[]
        for j in range(len(mat2[0])):
            a.append(0)
        ans.append(a)
    for i in range(len(mat1)):
        for k in range(len(mat2[0])):
            for j in range(len(mat2[0])):
                ans[i][k] += mat1[i][j] * mat2[j][k]
    return ans

def transpose_matrix(a):
    tans=[]
    for i in range(len(a)):
        t=[]
        for j in range(len(a[i])):
            t.append(0)
        tans.append(t)
    for i in range(len(a)):
        for j in range(len(a[i])):
            tans[j][i]=a[i][j]
    return tans






def main():


    print("Enter elements for Matrix A\n")
    Matrix_1=read_matrix()
    print("Matrix A : ")
    display_matrix(Matrix_1)
    print("Enter elements for Matrix B\n")
    Matrix_2=read_matrix()
    print("Matrix B : ")
    display_matrix(Matrix_2)

    while(True):
        print("1. Addition of matrices\n2.Subtraction of matrices\n3.Multiplication of matrices\n4.Transpose of matrix A\n5.Transpose of matrix B")
        ch=int(input("Enter your choice :" ))

        if ch==1:
            add_matrix(Matrix_1,Matrix_2)
            print("Addition of Matrix A and B is :\n")
            display_matrix(Addn)

        if ch==2:
            print("Subtraction of Matrix A and B is :\n")
            sub_matrix(Matrix_1,Matrix_2)
            display_matrix(Subn)

        if ch==3:
            print("Multiplication of Matrix A and B is :\n")
            multi=multiply_matrix(Matrix_1,Matrix_2)
            display_matrix(multi)

        if ch==4:
            transpose=transpose_matrix(Matrix_1)
            print("Transpose of Matrix A : \n")
            display_matrix(transpose)

        if ch==5:
            transpose_2 = transpose_matrix(Matrix_2)
            print("Transpose of Matrix B : \n")
            display_matrix(transpose_2)

        if ch>=6:
            print("Oops! Wrong choice entered.\nPlease try again")
            break
main()
