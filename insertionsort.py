def insertionSort(L, n):

    # base case
    if n <= 1:
        return

    insertionSort(L, n - 1)


    tomove = L[n-1]
    tocompare = n-2

    while tocompare >= 0 and tomove < L[tocompare]:
        L[tocompare + 1] = L[tocompare]
        tocompare -= 1

    L[tocompare+1] = tomove


L = [5,4,3,2,1]
insertionSort(L, len(L))
print(L)