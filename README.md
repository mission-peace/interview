
### Please visit my wiki link for full list of questions
#### https://github.com/mission-peace/interview/wiki

### Like my facebook page for latest updates on my youtube channel
### https://www.facebook.com/tusharroy25

### Contribution
Please contribute to this repository to help it make better. Any change like new question, code improvement, doc improvement etc. is very welcome. Just send me a pull request and I will review the request and approve it if it looks good.

## How to use this repository

###  Softwares to install ###
1. Install JDK8 https://docs.oracle.com/javase/8/docs/technotes/guides/install/install_overview.html
2. Install Git https://git-scm.com/book/en/v2/Getting-Started-Installing-Git
3. Install either:
  * Intellij https://www.jetbrains.com/idea/download/
  * If you like eclipse instead of intellij install eclipse https://eclipse.org/downloads/

###  Set up your desktop ###
* Pull the git repository. Go to command line and type git clone https://github.com/mission-peace/interview.git
* Go to root directory of checked out project.
* Run ./gradlew idea to generate idea related classes
* Fire up intellij. Go to Open. Go to git repo folder and open interview.ipr . On file menu go to project structure. Update language level support to 8
* If you use eclipse, do ./gradlew eclipse . This will generate eclipse related files. Go to eclipse and open up folder containing this repo.
* Go to any program and run that program
* Go to any test and run the junit test.
* Run ./gradlew build to create classes, run tests and create jar.
