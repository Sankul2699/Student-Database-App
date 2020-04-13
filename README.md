# Student-Database-App
 The Student Database App can store a huge data base using dynamic memory allocation hence making use of memory very effeciently. 
 It stores student’s Name, Date of Birth dynamically and Marks to a file(excel) while automatically assigning each student a roll number.
 
 The Gui interface has been done using Win32.

 Win32 is the 32-bit application programming interface (API) for versions of Windows from 95 onwards. The API consists of functions implemented, as with Win16, in system DLLs. The core DLLs of Win32 are kernel32.dll, user32.dll, and gdi32.dll. Win32 was introduced with Windows NT. The version of Win32 shipped with Windows 95 was initially referred to as Win32c, with c meaning compatibility. This term was later abandoned by Microsoft in favor of Win32.
 # THE APP INTERFACE
 ![](https://github.com/Sankul2699/Student-Database-App/blob/master/Images/front%20main.JPG) 
 
 This is the frist window which appears after lauching the  app
 It has two Options ADMIN DATABASE 
 # -ADMIN
We can store student data through it. 
It can be accessed only by admins as it asks for password.
First enter password to move ahead. (the password can be set in the code by opening it in a c++ compiler)
![](https://github.com/Sankul2699/Student-Database-App/blob/master/Images/password.jpeg)
press verify to move ahead

-STUDENT INFORMATION ENTRY
-
This window appears after the password is verified
![](https://github.com/Sankul2699/Student-Database-App/blob/master/Images/Student%20info%20entry.jpeg)
The information is entered in respective field
if the information entered is not valid it does not take the input
![](https://github.com/Sankul2699/Student-Database-App/blob/master/Images/wrong%20entries.jpeg)

# -DATABASE
The stored data can be checked through it by entering the position(roll no)

![](https://github.com/Sankul2699/Student-Database-App/blob/master/Images/student%20details.jpeg)
And by pressing submit it shows the sored data.

# AUTOMATIC FILE GENERATION(EXCEL)

![](https://github.com/Sankul2699/Student-Database-App/blob/master/Images/exel%20store.jpeg)

A file name Database.csv will be generated iside the folder and the whole database with squence will be stored in it.

