# Inline Calculator (c++)

This code takes a string that include numbers and math operator. An example of the input string is "1-2-4\*5\*6+7". The code should consider the order of operations (first \*, then + and -). The result for the string "1-2-4\*5\*6+7" should be -115.
Here is the process that is implemened in the given code:

* We should first take care of multiplications.
* Replace the results of multlipications back into the string. The result of the example "1-2-4\*5\*6+7" is "1-2-120+7".

* Finally, we take care of the + and - operations. Th esolution for the above example is "-114".

The defined class Solution includes the following methods, which following the aforementioned steps:

(1) "void Solution::mult_func(string&)" which only takes care of \* operator, edits the string by replacing the \* and the numbers on both sides of the operator * with the result of the product. After running the function, the initial string will no longer include \* sign.

(2) "int Solution::summation(string &s)" which uses the edited string, and benefits from recursion to take care of the summation and substraction.

(3) "int Solution::calculate(string s)" calls the aforementioned functions in the ordered explained above and return the calculated result.

* It is noted that the function "int Solution::to_int(char c)" is introduced to convert each char to int.

Here is the result for a some examples:

![Screenshot 2023-09-13 at 9 58 10 AM](https://github.com/sahandmsh/Calculator/assets/82970651/549f7177-8f4b-413f-a449-f80b0fd97284)





