# nfr-learn-labs
This repository includes firmware and other materials intended for use within NFR Learn's Electrical Lessons.

Students will be expected to fork this repository, and clone it to their local machine. They will then use git to keep track of their changes, and get comfortable with the development process.

Check out the [NFR Learn](https://nfr-learn.ue.r.appspot.com/) website for more information on the lessons and labs. 

## Labs

The following labs are available for students to complete:

- [Lab 0: Setup, Setup, Setup!](lab_0/README.md)
- [Lab 1: Introduction to Breadboarding](lab_1/README.md)
- [Lab 2: Morse Code](lab_2/README.md)
- [Lab 3: Game Controller Design](lab_3/README.md)
- [Lab 4: Heart Rate Monitor (pt. 1)](lab_4/README.md)
- [Lab 5: Heart Rate Monitor (pt. 2)](lab_5/README.md)
- [Lab 6: Game Controller System](lab_6/README.md)

*Note, Lab 5 is a continuation of Lab 4. As such, you will continue to work on the same code, located in the `lab_4` directory.* Instead of having code for that you can build off of in the `lab_5` directory, there is the firmware for the "doctor" side of the heart rate monitor system. This firmware is located in the `lab_5` directory, and is not intended to be modified by students.

## Notes About Opening Projects

Whenever you open a lab in VSCode, *do not* open the entire `nfr-learn-labs` directory. Instead, open the individual lab directory. In order to take advantage of PlatformIO's features, you need to open the directory that contains the `platformio.ini` file. This file is located in each lab's directory.

To check if you have opened the correct directory, look at the top left corner of the VSCode window. You should see the name of the lab you are working on. If you see `nfr-learn-labs`, you have opened the wrong directory. You should see something like `lab_0` or `lab_1` instead.
