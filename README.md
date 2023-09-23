# Inline Calculator (C++)

This code takes a string that include numbers and math operator. An example of the input string is "3-4\*5\*2-3-4". The code should consider the order of operations (first \*, then + and -). The result for the string "3-4\*5\*2-3-4" should be -44.
Here is the process that is implemened in the given code:

* We first take care of multiplications.
* Then, we take care of the + and - operations.

A stack is used to extract numbers from the string and store them (operands stack). The defined calculator function includes the following steps:

(1) if there is no "+" or "-" operator at the beginning of the string, insert a "+" sign.

(2) iterate through the string. There are two general cases:
    
    (a) s[i] == "-" || s[i] == "+". In this case, the operator defines the sign of the number at s[++i]; So, push the resulting number into the operands stack.
  
    (b) s[i] = "\*". In this case, pop out the top number in the stack, and extract the number right next to the "*" in the string s (s[++i]). Calculate the multiplication and push the result into the stack.
(3) Keep iterating through the string s until reaching the end.

Here is a simple example of the steps 1-3:
s="3-4\*5\*2-3-4";  -> s= "+3-4\*5\*2-3-4"

![Screenshot 2023-09-23 at 2 54 14 PM](https://github.com/sahandmsh/Calculator/assets/82970651/c12ec6a8-24c2-4859-8e94-18692a66883c)

(4) pop numbers out of the stack one by one and add them all together. The result of the summation is the answer.






Here is the result for some examples:

![Screenshot 2023-09-13 at 9 58 10 AM](https://github.com/sahandmsh/Calculator/assets/82970651/549f7177-8f4b-413f-a449-f80b0fd97284)





