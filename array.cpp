#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int enumerate (const string array[], int size, string target);
int locate(const string array[], int size, string target);
bool locateSequence(const string array[], int size, string target, int& begin, int& end);
int locationOfMin(const string array[], int size);
int moveToEnd(string array[], int size, int pos);
int moveToBeginning(string array[], int size, int pos);
int findDifference(const string array1[], int size1, const string array2[], int size2);
int removeDups(string array[], int size);
bool subsequence(const string array1[], int size1, const string array2[], int size2);
int makeMerger(const string array1[], int size1, const string array2[], int size2,
               string result[], int max);
int divide(string array[], int size, string divider);




int main () {

string function1[5]{"john", "bill", "jack", "juan", "juan"};
    /*
     assert statements below will test multiple conditions for the function "enumerate". confirms the function will return -1 when size of array is inputted as < 0.
     */
    assert (enumerate(function1, 5, "jill") == 0);
    assert (enumerate(function1, 5, "Bill") == 0);
    assert (enumerate(function1, 5, "juan") == 2);
    assert (enumerate(function1, 3, "juan") == 0);
    assert (enumerate(function1, -1, "bill") == -1);
    
    /*
       assert statements below will test multiple conditions for the function "locate" to ensure all errors are detected. confirms the function will return -1 when size of array is inputted as < 0.
       */
    
    string function2[5]{"john", "bill", "jack", "juan", "juan"};
    
    assert (locate(function2, 1, "jack") == -1);
    assert (locate(function2, 5, "juan") == 3);
    assert (locate(function2, 0, "jack") == -1);
    assert (locate(function2, 5, "bill") == 1);
    assert (locate(function2, 4, "JUAN") == -1);
    assert (locate(function2, -1, "john") == -1);
    
string locateSeqTest[7]{"hanz", "willie", "willie", "willie", "joe", "bill", "bill"}; // string[] for testing function "locateSequence"
    
int begin = 0;
int end = 0;
    
    assert (locateSequence(locateSeqTest, 5, "andre", begin, end) == 0 && begin == 0 && end == 0);
    assert (locateSequence(locateSeqTest, 7, "willie", begin, end) == 1);
    assert (locateSequence(locateSeqTest, 7, "bob", begin, end) == 0);
    assert (locateSequence(locateSeqTest, 7, "willie", begin, end) == 1 && begin == 1 && end == 3);
    assert (locateSequence(locateSeqTest, -1, "willie", begin, end) == 0);
    
    
string locateMin [7]{"panz", "willie", "willie", "willie", "joe", "joe", "will"};

    
    assert (locationOfMin(locateMin, 5) == 4);
    assert (locationOfMin(locateMin, -1) == -1);
    assert (locationOfMin(locateMin, 0) == 0);
    assert (locationOfMin(locateMin, 7) == 4);
    
string movetoEnd2[4] = { "samwell", "jon", "daenerys", "tyrion" };
string g[4] = { "samwell", "jon", "daenerys", "tyrion" };

    assert(moveToEnd(movetoEnd2, 4, 1 ) == 1 && movetoEnd2[1] == "daenerys" && movetoEnd2[3] == "jon" );
    assert(moveToEnd(movetoEnd2, 4, 0) == 0);
    assert(moveToEnd(g, 4, 4) == -1);
    

string ToBeginning[6]{"bob","ralph","sally","jed","tanner","will"};
  
    assert(moveToBeginning(ToBeginning, 6, 1)== 1 && ToBeginning[0] == "ralph" && ToBeginning[1] == "bob");
    assert(moveToBeginning(ToBeginning, 6, 4) == 4 && ToBeginning[0] == "tanner" && ToBeginning[4] == "jed");
    assert(moveToBeginning(ToBeginning, 6, 6) == -1);
    assert(moveToBeginning(ToBeginning, 4, 6) == -1);
    assert(moveToBeginning(ToBeginning, -1, 4) == -1);
    
    
string findDiff1[5]{"jon","bill","will","sam","mark"};
string findDiff2[5]{"jon","bill","stevie","sam","wallace"};
string findDiff3[3]{"jon","bill","will"};
  
    assert(findDifference(findDiff1, 2, findDiff2, 1) == 1);
    assert(findDifference(findDiff1, 1, findDiff2, 2) == 1);
    assert(findDifference(findDiff1, 5, findDiff2, 3) == 2);
    assert(findDifference(findDiff1, 5, findDiff3, 3) == 3);
    assert(findDifference(findDiff2, 5, findDiff3, 3) == 2);
    assert(findDifference(findDiff2, 5, findDiff3, -1) == -1);
    
string dupTest1[9]{"jon","jon","bill","bill","danny","tom", "will","will", "cindy"};
string dupTest2[5]{"jon","andy","bill","bill","danny"};
string dupTest3[7]{"jon","andy","bill","bill","danny", "danny", "danny"};

    assert (removeDups(dupTest1, 0) == 0 && dupTest1[0] == "jon" && dupTest1[1] == "jon");
    assert (removeDups(dupTest1, 4) == 2 && dupTest1[1] == "bill");
    assert (removeDups(dupTest1, 9) == 6 && dupTest1[2] == "danny" && dupTest1[5] == "cindy");
    assert (removeDups(dupTest2, 4) == 3);
    assert (removeDups(dupTest2, -1) == -1);
    assert (removeDups(dupTest3, 7) == 4);
    
string subSeq1[8]{"alex","mark","bill","willie","daniel","steve","max","dave"};
string subSeq2[3]{"bill","daniel","max"};
string subSeq2a[0]{};
string subSeq2b[3]{"daniel","bill","dave"};

    assert(subsequence(subSeq1, 8, subSeq2, 3) == 1);
    assert(subsequence(subSeq1, 4, subSeq2, 3) == 0);
    assert(subsequence(subSeq1, 8, subSeq2a, 3) == 0);
    assert(subsequence(subSeq1, 8, subSeq2b, 3) == 0);
    assert(subsequence(subSeq1, 8, subSeq2b, -1) == 0);

    

const string merger1[5]{"ben","dave","fred","john","victor"};
const string merger2[5]{"charlie","don","hank","pat", "zinc"};
const string merger2_a[5]{"charlie","abel","hank","pat", "zinc"};
string result[100]{};
   
    assert (makeMerger(merger1, 5, merger2, 5, result, 18) == 10 && result[1] == "charlie" && result[8] == "victor");
    assert (makeMerger(merger1, 5, merger2, 5, result, 9) == -1);
    assert (makeMerger(merger1, 5, merger2, 2, result, 18) == 7 && result[4] == "fred");
    assert (makeMerger(merger1, 5, merger2_a, 5, result, 18) == -1);
    assert (makeMerger(merger2_a, 5, merger1, 5, result, 18) == -1);
    
    
string divide1[6]{"will","adame","dave","nick","larry","bubba"};
string divide2[7]{"will","adame","dave","nick","larry","wally", "karen"};
string divide3[7] = {"samwell", "jon", "margaery", "daenerys", "", "tyrion", "margaery"};
string divideAns[100]{};
string h[7] = { "samwell", "jon", "margaery", "daenerys", "", "tyrion", "margaery" };
    
    
 
    assert(divide(divide1, 6, "zena") == 6);
    assert(divide(divide2, 7, "tom") == 5);
    assert(divide(divide3, 7, "margaery") == 3);
    assert(divide(h, 4, "ricky") == 3 && h[3] == "samwell");
    

}




int enumerate (const string array[], int size, string target)
{
    int targetCount = 0;
    for (int i=0; i<size; i++) // loop goes through each element of                           //string
    {
        if (array[i] == target) // counts number of matches for target
            targetCount += 1;
    }
    if (size < 0) // if target matches nothing, return -1
    {
        return -1;
    }
        return targetCount;
}


int locate(const string array[], int size, string target)
{
    if (size < 0)
        return -1;
    for (int i=0; i<size; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }
    return -1;
}


bool locateSequence(const string array[], int size, string target, int& begin, int& end)
// begin and end variables are passed by reference
{
   if (size < 0)
   {
       return false;
   }
    for (int i=0; i<size; i++)
    {
        if (array[i] == target) // finds the first position that                              matches target
        {
            begin = i;
            end = i;
            i++;
           while (array[i] == array[i-1]) // loop to find position of                                   end if target is found
           {
               end = i;
               i++;
           }
            return true;
        }
    }
    
    return false; // if no target is found the variables &begin and                 &end are not changed in main function, and the                  function returns false
}



int locationOfMin(const string array[], int size)
{
    if (size < 0)
        return -1;
    else if (size == 0)
        return 0;
    
    
    int smallPosition = 0; // sets first position to smallest, only changes when following position is                          smaller
    for (int i=0; i<size; i++)
    {
        if (array[i] < array[smallPosition])
            smallPosition = i; // loop goes through array and sets smallest position when it sees it
    }
    
    
    
    return smallPosition;
    
}



int moveToEnd(string array[], int size, int pos)
{
string posName;
    if (size < 0 || pos >= size)
        return -1;
 
    for (int i = 0; i < size; i++)
    {
        if (i == pos)
        {
            posName = array[i];
            while (i < size-1) // loop moves value of index one space to                  left
                {
                    array[i] = array[i+1];
                    i++;
                }
        array[size - 1] = posName; // sets the chosen value to be                               placed in the last position of                              the array
         // exits loop once positions are moved
            
        }
     
        
    }
    

   
    return pos;
    
}



int moveToBeginning(string array[], int size, int pos)
{
string posName;
if (size < 0 || pos >= size)
    return -1;
    
      for (int i = 0; i <= pos; i++) // loop to find desired position moved
      {
         if (i == pos) // finds array value to be put in front
         {
             posName = array[i];
             while(i > 0) // loop changes values left of position one spot to the right
             {
                 array[i] = array[i-1];
                 i--;
             }
             array[0] = posName;
             break; // ends loop once positions are changed to desired location
         }
      }
   
      return pos;
}




int findDifference(const string array1[], int size1, const string array2[], int size2)
{
    
   if (size1 < size2)
   {
    for (int i = 0; i < size1; i++)
    {
          if (array1[i] != array2[i])
              return i;
    }
       return size1;
   }
    
    
    if (size2 < size1)
    {
        for (int i = 0; i < size2; i++)
        {
            if (array1[i] != array2[i])
                return i;
        }
        return size2;
    }
    
    
    if (size1 == size2)
    {
        for (int i = 0; i < size1; i++)
        {
            if (array1[i] != array2[i])
                return i;
        }
    }
    
  
    if (size1 < 0 || size2 < 0)
    {
        return -1;
    }
    
    
    return 0;
}



int removeDups(string array[], int size)
{ //"jon","jon","jon","bill","bill","danny","tom","mark",              "alex", "sally"
    if (size < 0)
        return -1;
    
    int j = 0;
    int remaining = 0;
        for (int i = 0; i < size; ++i)
        {
            if (array[i] != array[i+1]) // coniditonal sets non duplicate elements up front and throws the duplicates in the back of array
            {
                remaining = remaining + 1; //counts # of retained elements in array
                array[j] = array[i];
                j++;
                
            }
            
        }
        
    return remaining; // returns number of non duplicate elements
}




bool subsequence(const string array1[], int size1, const string array2[], int size2)
{
    
int count = 0;
int i = 0;
int j = 0;
   
    while(i < size1) // loops through larger array
    {
        if (array1[i] == array2[j]) // finds out if smaller array has common elements in order
        {
            count+=1; // counts elements in common that are in order
            j+=1;
        }
        if (count == size2) // finds out if elements found is same size as smaller array
        {
            return true;
        }
        
        i++;
    }
  return false;
}




int makeMerger(const string array1[], int size1, const string array2[], int size2,
string result[], int max)
{
    if (size1 < 0 || size2 < 0)
    {
        return -1;
    }
    
    int a1 = 0;
    int a2 = 0;
    int lowest = 0;
    
    if (max < size1+size2) // makes sure max is >= size of result array
        return -1;
  
    for (int m = 0; m < size1-1; m++) // loop checks if array1 is in nondecreasing order
    {
        if (array1[m] > array1[m+1])
            return -1;
    }
    
    for (int n = 0; n < size2-1; n++) // loop checks if array2 is in nondecreasing order
       {
           if (array2[n] > array2[n+1])
               return -1;
       }
    
    
    for (int i = 0; i < size1+size2; i++) // loop arranges merged array in nondecreasing order
    {
      if (array1[a1] < array2[a2])
      {
          result[lowest] = array1[a1];
          lowest++;
          a1++;
      }
      else if (array2[a2] <= array1[a1])
      {
          result[lowest] = array2[a2];
          lowest++;
          a2++;
      }
        
    }
 
    return size1 + size2;
}



int divide(string array[], int size, string divider)
{
    if (size < 0)
    {
        return -1;
    }

int begin = 0;
int end = size-1;
string answer[100]{};
    
    for (int i = 0; i < size; i++)
    {
        if (array[i] >= divider) // sets element to the back of the new array if its greater than divider
        {
            answer[end] = array[i];
            end--;
            continue;
        }
        else if (array[i] < divider) // sets element to front of the new array if its <= divider
        {
            answer[begin] = array[i];
            begin++;
            continue;
        }
        
        
    }
    
    
    for (int k = 0; k < size; k++) // assigns the new order to the original array
        {
            array[k] = answer[k];
        
        }
        
    for (int k = 0; k < size; k++) // returns position of first value greater or equal to divider
           {
               if (array[k] >= divider)
                   return k;
           }
    


    return size;
}
