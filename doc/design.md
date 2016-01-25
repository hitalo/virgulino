# Virgulino C version Project Design.


Introdution
---

Well, the headers filenames and their functions were cautious 
selected to help the coder to undertand what every function 
does and for better understanding about responsabilities on
the project itself. 

Headers project definitions
---

 **color_set.h** -

   A set of codes to define colors on output. It can be useful
   for many reasons.

**definitions.h** -

   A bunch of macros and precompiled definitions to be used on 
   anothers headers.

**output.h** -

   It has every function to handle with any output provided by 
   virgulino.

 **virgulinho.h**

   Where commandline arguments are treated and to variables are
   configured to satsfy the proper arguments given by the end-user.

 **cypher_utils.h** -

   A bunch of utilitary functions to help on the cyphering/encrypting
   decyphering/decrypting processes.

 **cypher.h** -

   The functions that will actually encrypt/decrypt the message.
 
 **main.c** -

   Where everything happens.

Conclusion
---

That's the bunch of headers and theirs responsabilities. I designed the project this way because I believe that it can help
anyone to better understand the project structure and consequently contribute.

