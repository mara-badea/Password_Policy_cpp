## About

Creating a library to add additional security elements for a web app. These password policies can be configured for the app/website and the passwords created by the users will be checked according to the password policies.

## Structure

### For creating the library I used the following file:

-main.cpp

## Description of the algorithm:

  The password policies are:
  
  <p>-<b>Length</b>: it can specify either the minimum length or the minimum and maximum length; length min_length or length min_length, max_length</p>
  <p>-<b>Class</b>: it specifies how many different classes of characters the password must have at least. The classes are: non-capital letters, capital letters, digits and special characters.</p>
  <p>-<b>Must Include</b>: the password must include at least a character from the specified class of characters: "a" (non-capital letters), "A" (capital letters), "0" (digits), "$" (special characters). </p>
  <p>-<b>Must Not Include</b>: the password must not include any character from the specified class of characters: "a" (non-capital letters), "A" (capital letters), "0" (digits), "$" (special characters).</p>
  <p>-<b>Repetition</b>: it specifies how many times the same character can repeat itself consecutively in the password</p>
  <p>-<b>Consecutive</b>: it specifies the maximum number of consecutive characters (e.g.:abc or 123)</p>
  
  <p>Given the password policies, and then a list of passwords, it will be returned either <b>"OK"</b> if the password meets the conditions of the password policies, or <b>"NOK"</b> if the password does not meet the conditions of the password policies.</p>
  
  <p><b>Examples</b>:
  
  <b>INPUT</b>:
  
  5  > number of password policies
  
  length 8
  
  include 0
  
  include A
  
  include $
  
  repetition 2
  
  Sp!llthetea33
  
  App!33
  
  Appl!333
  
  H0ldMyB33r!
  

  <b>OUTPUT</b>:
  
  OK
  
  NOK
  
  NOK
  
  OK</p>

  
