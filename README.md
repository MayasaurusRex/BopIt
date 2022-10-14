# Bop-It
## 1. Design Overview
### 1.1 Description and purpose
The purpose of the design for the Bop-It project was to create a prototype of a product that is inspired by a Guitar Hero controller and follows the Bop-It logic of user inputs. An image of the guitar hero controller can be seen below.
\
![image](https://user-images.githubusercontent.com/67076014/195931919-f5331376-b1a5-4b21-9baf-a8012ffcadef.png)

### 1.2 Original design concepts
Before landing on a final project idea, our group discussed two other ideas. The first was a standard Bop-It with twist, pull, and push controllers. The second was a DJ board with inputs of a rotary encoder, slide switch, and push button. Both of these options had straightforward enclosure designs since they could be laser cut boxes.

Ultimately, we decided to choose the guitar design. The enclosure of the guitar posed a challenge to us since it was complex and required 3D printing, which none of us had experience with before the project.

### 1.3 Final design
The guitar design we chose to go with included three user inputs: a fret button, strum switches, and a whammy bar. The user would get audio inputs from a piezo buzzer and an LCD screen would display the required action, successes, failures, and the user’s current score. An ATMega328p chip and Arduino code control the logic of the circuit. On the software side, polling is used for inputs, random numbers are used for deciding next actions, and flags are used for program flow. The enclosure required over 54 3D printed parts and several hours of total printing. The final assembled product can be seen below.
\
![IMG_3551 2](https://user-images.githubusercontent.com/67076014/195932043-807e6176-3d52-46c4-9d89-91cbbaf8a949.png)

## 2. Design Verification - Breadboard Prototype
### 2.1 Breadboard components	
When simulating this circuit on a breadboard, we tried to find as many relevant components as we could to best simulate the design. We used the LCD display with an I2C converter to display the score and user prompts, a push button for the fret input, a potentiometer for the whammy input, and a piezo buzzer for the sound output. Instead of using switches to model the strum, we used push buttons since we did not have switches at the time of prototyping. Below is an image of the ATMega328p setup we used.
\
![Note Jun 27, 2022](https://user-images.githubusercontent.com/67076014/195932160-93004164-ef5f-45b8-818f-d4d84c1f9719.png)

### 2.2 Breadboard Setup
The breadboard setup was vital to the planning of the hardware, software, and enclosure because it showed us the layout needed for the PCB, the software setup for tracking the pins, and the sizing required for the overall enclosure. Below is an image of the overall breadboard setup.
\
![image](https://user-images.githubusercontent.com/67076014/195932353-a104866f-8287-49e5-9c8f-822839df5f0f.png)


### 2.3 Breadboard Testing and Results	
We tested our prototype on its handling of successful game playing, reaction time failures, and incorrect input failures.
A video of our completed breadboard prototype can be found here: https://youtu.be/G3_sWDcgMCE 

## 3. Electronic Design Implementation

### 3.1 PCB schematic	
The first part of the PCB design was recreating the “Hello World” assignment setup. This is the minimum requirement for the board to function. This part of the schematic is shown on the microcontroller page and components shown in the green box on the I/O and Power page. This includes the microcontroller, oscillator with coupling capacitors, voltage regulator with coupling capacitors, programmer header, and reset pull-up resistor. 
\
![PCB_Schematic](https://user-images.githubusercontent.com/67076014/195932420-7d489f32-c285-4609-9b44-d3ed34b1a7f4.png)
\
<img width="648" alt="Screen Shot 2022-10-14 at 3 49 15 PM" src="https://user-images.githubusercontent.com/67076014/195932518-2659f330-d208-4735-85d6-203ab4b4db48.png">

\
The remaining part of the design was the I/O of the device: all of which is not on the PCB, but connected to the PCB through headers. This includes the I2C display, the whammy potentiometer with its current-limiting resistors, the success and failure LEDs with their current-limiting resistors, the buzzer, and the fret button, two strumming switches, and reset button, each with their own pull-up resistors (the pull-up resistor for the reset button is shown on the microcontroller page). There is also a header to power the built-in LED on the arcade button, but this functionality was not included in the final design because of space limitations for wiring.

### 3.2 PCB layout
![image](https://user-images.githubusercontent.com/67076014/195932900-881475e3-97c1-48ac-b4bd-699519cd670f.png)
\
![image](https://user-images.githubusercontent.com/67076014/195933022-cb3a4454-a391-4b64-8889-c906923fe622.png)

Above is shown the front and back layout for the PCB. The top plane is the 5V Vcc plane, and the bottom plane is the ground plane. The microcontroller is centrally located and the power input and regulator are in the bottom right-hand corner. All I/O, the programmer header, and the crystal oscillator are arranged around the microcontroller in the order of where they connect to it to reduce crossing of traces. The only exceptions to this are the reset and MISO pins of the programmer header, which have to be routed on the bottom of the board through vias. Capacitor C4 is a coupling capacitor between Vcc and Ground, so it can go anywhere on the board where the planes are not cut off by traces.	
\
The use of Vcc and ground planes made soldering to those planes slightly more difficult, but made the layout design much simpler. There are two holes for mounting the PCB in the enclosure with M3 screws, but it was decided to not mount the board in this way.

## 4. Software Implementation

### 4.1 Code structure
To drive the logic of the Bop-It, the software uses a mix of subroutines, polling, and flags. The subroutines help with choosing a random task and handling user inputs, the polling helps “listen” for user inputs, and the flags help control the loop function which is central to Arduino code.
The following flags are used in the code:
first => tracks the first time that the code runs, helps control the flow of the program
failure => tracks the users success or failure so the program knows when to end
The first time the program runs, the subroutine to choose a random task is called. That subroutine gives the output associated with the task, and then the software polls for any user input. If the user gives an input, another subroutine is called to verify if the input is correct or not. If the user does not give an input, a counter counts down until the time is out, at which point the user fails. A success will decrease the allotted reaction time.

### 4.2 Subroutines and files
#### 4.2.1 flags.h
The flags header file is used to maintain all the global variables and flags that are used throughout the program. The flags include “first” to track the start of the game, and “failure” to track the user success within the game. The global variables include the current task, the current score, and the reaction time so that all subroutines can access it.
#### 4.2.2 pinmap.h
The pinmap header file is vital to the ease of the program, especially during the integration and design testing parts of the project. Here, all the variables are assigned to pin header locations, so that they only need to be changed once within the program if necessary.
#### 4.2.3 pitches.h
The pitches header file is from Arduino. It is the initialization of the notes that the piezo buzzer can use. It is very helpful to be able to change the notes without having to memorize the frequency values of them.
#### 4.2.4 PinSetup
The PinSetup function assigns all the variables as either input or output pins. This is helpful because it makes the actual setup function a lot cleaner, especially since it only has to be called once.

#### 4.2.5 setup
The setup function runs once and initializes the LCD display, sets the AREF value to default, calls the subroutine to set up the pins, and then declares a random seed to analog pins so that any pseudo-random values can be used throughout the program.
#### 4.2.6 loop
The loop function continuously runs and uses the flag values to determine the logic. If it is the first time the loop runs, the subroutine to choose a task is called. If the user has not failed yet, the subroutine to poll for the input is called. The reaction time (counter based) is decremented, and if it reaches zero, the input handler subroutine will be called with a failure value.
#### 4.2.7 ChooseTask
The choose task subroutine randomly selects a number that is designated to each input. Then it displays it on the LCD screen and outputs the buzzer frequency associated with the chosen task. It also sets the global variable to the chosen task so that other subroutines can access it.
#### 4.2.8 PollInput
Poll input repeatedly checks for user input. The first input that comes in will be checked against the current task. If it is the same, the input handler subroutine will be sent a success signal, otherwise it will be sent a failure signal.
#### 4.2.9 InputHandler
If the input handler subroutine gets a success signal, it increments the score and decrements the allotted reaction time. It also displays success on the LCD screen and turns the LED green to give a visual cue of success.
If the input handler subroutine gets a failure signal, it displays failure on the LCD screen along with the final score. It turns the red LED on and changes the failure flag so that the loop will end the game.
### 4.3 Software design process
Creating the software to control the game took a lot of planning and small, iterative steps. It was important to reach small milestones before larger ones. For example, we ensured that individual components worked before combining all of them. Below is an image from when we tested our LCD display that used an SPI to I2C converter.
\
![image](https://user-images.githubusercontent.com/67076014/195933092-1594a8ad-3661-4048-84a7-c54b29a80d3f.png)

As more components were added, it was necessary to continually test. The breadboard prototype, as described in detail in section 2 was vital to the success of our project since it helped debug software issues before it was time to integrate.

One issue we did run into, however, was in regards to the bootloaders. We learned that some chips handle code differently, even if it was the same make and model (ATMega328p). When it was time to integrate, we downloaded the code onto a new chip and the logic didn’t match what was on the original chip, even with the same code. To remedy this problem, I conducted a lot of testing and learned that changing the delay times of the code helped maintain the logic. I saved that under a separate branch in the code repository so that we would easily be able to access it in the future if necessary.

## 5. Enclosure Design
### 5.1 Enclosure design process
The enclosure design was developed and completed in an iterative process.  The overall enclosure was 3D printed in the shape of an electric guitar.  Each piece was created based on specifications from an example guitar found on thingiverse.com.  Those pieces were then edited to meet the requirements of our project, specifically by changing the shapes, sizes, positions, and overall number of inputs and outputs to match those in our game.  In most cases, an initial form of the guitar component was printed, compared to our needs, edited, and then reprinted as a final product.  This allowed greater specification and customization of each piece needed.  The largest, external facing pieces were refined and printed first, as they would be the most obvious in the design and needed to be verified before the complete enclosure could be finalized.  Once the general case for the game was printed, the whammy and strum pieces and supports were printed, as they were the most complex.  Once all functional pieces were printed, the decorative pieces such as the buttons on the neck of the guitar were printed. 
\
![image](https://user-images.githubusercontent.com/67076014/195933153-e947413b-1b5d-45bd-b679-e34ba5ee929a.png)

### 5.2 Enclosure makeup and structure
The makeup of the enclosure is entirely 3D printed PLA plastic.  It is held together by a mixture of superglue and loctite gel, depending on the pieces in question.  Most of the larger components are held together with loctite, as it is strong and specifically recommended for 3D printed components.  Most of the smaller components were held together with super glue as it is strong and bonds quickly.  The whammy bar is held in place by a 3D printed round holder, attached to the hole on the top of the guitar intended for it.  The strum functionality is a 3D printed wedge, on two 3D printed mounts, held together with two 3D printed joints, resting on a 3D printed holder attached to the bottom of the guitar’s bottom.  This allows for access to the strum functionality without the switches being exposed. The fret button is simply through a designated hole on the neck enclosure.  The buzzer, reset button, LEDs, LCD display, and power button all are simply placed into the enclosure at designated locations where holes were placed. The front and back of the enclosure were designed so that they simply snap together, allowing for them to be easily assembled and be capable of being disassembled if needed.  The neck of the guitar has two pieces, one in the back and one in the front.  The front piece snaps on over the back piece, fitting securely without additional assistance such as superglue.  There are three additional pieces on the end of the neck that are only for decoration. 

### 5.3 Enclosure manufacturing process
The enclosure was manufactured using Pitt’s Virtual Labs in the Hillman Library.  Each piece was printed on either an Ultimaker 3 or an Ultimaker S5.  This was done over a series of six prints, each taking between 17 and 21 hours and containing 8 to 12 pieces.  One of the prints had to be done twice due to a printer failure.  Most of the pieces were printed on the Ultimaker 3, however the neck of the guitar was long enough that those pieces had to be printed on the larger Ultimaker S5.  Each piece was printed using standard navy PLA, based on files generated for manufacturing in the Ultimaker Cura desktop application.  They were printed with supports that had to be removed, and some edges and holes had to be filed for assembly as they came out rougher or larger than intended. 

## 6. Assembly and system integration
### 6.1 Assembly methods
The electrical components in the system were assembled by soldering them to the PCB board.  The enclosure was assembled by aligning pre-determined ridges to fit and super gluing pieces to ensure they were secure enough.  The software component was assembled with the rest of the design by uploading the software to the ATMega chip then placing it into the PCB board.  The electrical components were secured to the enclosure using a mixture of super glue, electrical tape, and tightly fitting holes.  The guitar was assembled incrementally, starting at the edges and working into the leg of the guitar where the PCB was secured.  Some holes were filed down to make them larger or smoother for a better fit with the input and output components. 	

### 6.2 Assembly challenges and modifications
Fitting all the wires connecting the board to I/O into the limited space in the enclosure proved difficult. There were challenges with maintaining sturdy connections with wires being compressed as the enclosure was closed. 

## 7. Design Testing
### 7.1 Test plans, procedures, and outcomes
Initially, the software design was tested with the ATMega chip used, and a breadboard circuit matching that used on the PCB board to ensure that it would work.  The procedure for this test was to attempt every potential input against every potential directed input, and ensure it would work properly.  This test did use buttons instead of the switches for the strum due to those not being available yet, but the other inputs and outputs were the same.  This test was successful, with all inputs producing the correct outputs.  
Once the PCB was assembled, it was tested thoroughly with the components that it was intended to attach to, outside of the enclosure.  This test procedure was to play the game, ensuring that all inputs were ordered and successfully completed, and that the game would fail when the time ran out or an incorrect input was pressed.  This test was successful after some calibration on the potentiometer. 
After the entire enclosure was assembled, the game was tested fully to verify that it worked overall.  All inputs (whammy, strum, and fret) were tested when both correct and incorrect to verify that they could pass and fail when appropriate.  The timeout was tested on each instructed input to ensure that it would work.  The reset button was tested to ensure that it worked appropriately.  Each test was conducted by each member of the team to ensure that it would definitely work.  The game passed all tests conducted for both success and failure conditions. 	
### 7.2 Assembled prototype

### 7.3 Challenges encountered
We ran into an issue where the bootloader on our microcontroller was using a different standard for delay timing than the microcontroller used in the prototype. The microcontroller was computing delay using an internal clock instead of the external crystal oscillator. After receiving guidance from Madison, the error was fixed in software.

In the meantime, we assumed that the chip currently soldered to the board was malfunctioning or had possibly become damaged by the heat of soldering, so we tried to desolder the microcontroller from the PCB. This did not end up working, and we had not yet soldered any of the ordered headers to the board, so we opted to assemble a second board. This board had the socket for the microcontroller soldered to the PCB as well as headers which had arrived at the lab.

Later during testing, we ran into problems with reading the analog input of the potentiometer. We had an alternate Arduino sketch which would display the value being read in on the analog pin on the LCD, and this showed the maximum value of 1023 even as the voltage measured at the pin varied over a range of ~4V. We had an idea that it had to do with the analog reference (Aref) pin on the microcontroller and how that was configured in software. We reached out to the TAs of the class, who suggested that we disconnect Aref to leave it floating and use the internal analog reference of the microcontroller. The Aref pin was connected to ground on the PCB. At this point, the microcontroller was not soldered directly to the PCB, only mounted in a socket, so we were able to disconnect the Aref pin and then configure the reference in software. 
### 7.4 Final video
Our final video is posted to YouTube at this link: 

## 8. Summary, Conclusions, and Future Work
In summary, our project was a working guitar game with inputs of strum, whammy, and fret.  It scored users based on their completion of the assigned tasks in the allotted time.  The project was ultimately successful, as the game is playable with random instructions, working inputs and outputs, and a fully completed enclosure that does not expose the hardware or software.  Based on this project, we have concluded that it is important to start early and coordinate well as we did.  We have also concluded for the enclosure design that it should be done as early as possible, so that changes can be made as needed to fit the requirements of the project.  We have also concluded that making sure the software and hardware work together, and both fit inside the enclosure is key. 
\
\
In terms of takeaways for software development, we learned the importance of starting early and creating ways in which we can streamline the process if any changes need to take place. Especially with a microcontroller with limited memory on the chip, it’s important to be concise with the logic. Moving forward, it would be very helpful to plan out logic on paper before implementing it in code to better visualize how subroutines interact. The Scrum method was helpful to stay on track, but implementing Kanban specific to the software could really be beneficial.
\
\
In future PCB design projects or if we were to redo the PCB design for this project, these are the guidelines we would follow.  First, leave more space at the edges of the board in order for the board to be properly held/gripped during assembly. Some components near the edge of the board made it difficult to hold the board in the circuit board holder. Next, arrange components (especially headers) more neatly and in line. It makes a big impact on the aesthetics of the board.  There are basically no components on the board which are lined up with one another, and as a result the board looks very messy despite being fairly simple. We would take care to ensure a perfect match between the prototype setup and the PCB schematic. This could have fixed our error with Aref. We would also more carefully consider size limitations and mounting requirements for the board before beginning routing. Because the inside of the enclosure was not perfectly hollow, there was less open space for the board to go than we initially thought.  The main change that we would make to the enclosure would be to make it an inch or so deeper, to allow more room for wiring and components. 

