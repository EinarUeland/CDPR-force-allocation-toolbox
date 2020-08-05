Upon using this code, please reference the paper and code repository:
Ueland, E. S., Sauder., Skjetne.... (2020). Optimal force allocation .... ... (to be updated)
---------------------------------------------------
Required software:
-Verified to be working in MATLAB 2019a. 
-For older versions of MATLAB, one need to rerun COMPILEC_CODE.m to regenerate C-Code. (you need an appropriate C-Comppiler).
-For versions earlier than MATLAB 2018a, the syntax for manipulating Figures is different, such that some adaptations is needed to reproduce the figures.
There is little use of internal MATLAB functions, so there should not be a need for many MATLAB packages excluding the standard ones.  
---------------------------------------------------
Before using:
-Make sure to add the whole folder with subfolders to your MATLAB path.
---------------------------------------------------
For questions on the multimedia material, we prefer that you post the questions on Github https://github.com/EinarUeland/CDPR-force-allocation-toolbox . 
Questions can also be directed to Einar Ueland at "einar.s.ueland@gmail.com"
--------------------------------------------------
If run on a non-real-time setup, we emphasize that in order to reproduce good computational time data you should: 
-Set the MATLAB-process to Real-Time priority using Windows Task manager (or equivalent in other OS)
-Consider turning of the internet to prevent automatic updates and other related processes to interfere with task-scheduling of the computer.
-Exit other non-related applications and processes
---------------------------------------------------------------------------------------
Figures in the paper can be reproduced by running the following scripts;
GenerateFigures2Through10/GenFigures_2_7-> Figures 2 through 7
GenerateFigures11Through15/GenFigures_8_12-> Figures 8 through 12
---------------------------------------------------------------------------------------

