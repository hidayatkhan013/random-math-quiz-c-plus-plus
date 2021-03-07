# random-math-quiz-c-plus-plus

## Problem: Educational Software

```
Your little brother is having trouble with arithmetic. Your parents realize that after taking a few
weeks of programming course, you could potentially write a program that will allow him to practice
his arithmetic skills.
Your program should prompt your brother with the following menu:
P: Practice
Math S: Show
Score Q: Quit
When “P” is chosen, your program should then prompt him for the difficult level. The difficulty level
can be easy, medium, or hard. The difference between easy, medium, and hard is simply that in
easy level, the operand of each question should be from - 10 to 10. In medium, they can be
between -50 and +50. And in hard, they can be between -100 and 100.
Then it should prompt him with the desired number of problems. The questions can be addition,
subtraction, division, or multiplication. You really want to mix things up so there is no specific
order. Rather the program should randomly pick a question from addition, subtraction, division, or
multiplication. Furthermore, the operands for the questions should be randomly generated as well.
For division, you want to ensure the answer is a whole number.
Your program should keep track of how many answers are wrong and belong to which category
(Addition, Subtraction, Multiplication 0r Division).
At the end of the questions, the program should display:
```
- Score (See scoring details)
- How many questions the user got correct


- Breakdown of how many the user got correct for each type of arithmetic
- Areas where the user needs to improve. This would be any type in which the user had a
    single mistake (you really want your brother to score a 100 in the test).
Selecting “S: Score” should print out the last score the user had. If there is no score to display, then
display: “No score found”.
The menu should repeat unless the user chooses “Q: Quit”

### Scoring Details

Each question’s score will depend on the difficulty levels. (For example: easy: 2 marks, medium:
4 marks and hard: 5 marks). Show the individual difficulty question’s scores.


## Sample Output

```
Please make a selection from the following:
P: Practice Math
S: Show Score.
Q: Quit.
```
What do you want to do: **_S_**^
No score found.
What do you want to do: **_P_**
What difficult level do you want:
E: Easy
M: Medium
H: Hard
Enter difficult level: **_H_**
How many problems do you want? **_4_**
What is 21+86? **_107_**
Correct, great job!
What is 92/2? **_44_**
Sorry, that's incorrect, the answer is 46.
What is 86-70? **_16_**
Correct, great job!
What is 51*4? **_204_**
Correct, great job!
Your score is 15/

You got 3/4 questions correct.^
Addition Subtraction Multiplication Division


#### 1 /1 1/1 1/1 0/

```
Need more practice with:
Division
Please make a selection from the following:
P: Practice Math
S: Show Score.
```
Q: Quit.^
What do you want to do: **_S_**
Your last score was 15/20.
Please make a selection from the following:
P: Practice Math
S: Show Score.
Q: Quit.
What do you want to do: **_Q_**
Thank you for practicing!

