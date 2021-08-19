# Multinomial-Naive-Bayes
Implementation of Multinomial Naive Bayes Classifier in C++.

## Compilation Guide:

```console
vladiq@vladiq:~/DA$ cmake .
vladiq@vladiq:~/DA$ make
```


## How to Use:

Create a test file (examples are in the /testcases directory):

First line: n_train n_test

Then the sequence of n_train training examples like that:<br/>
class_n (0 or 1)<br/>
train_text

Then the sequence of n_test test examples:<br/>
test_text

## Example of usage:

```console
vladiq@vladiq:~/DA$ ./NB <testcases/test_01.test
1
0

```
