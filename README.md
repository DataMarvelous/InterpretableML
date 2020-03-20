# InterpretableML
Interpretable Machine Learning - Dominance Classifier Predictor Algorithm &amp; Reverse Pattern Prediction Recognition Algorithm

Interpretable Machine Learning with DCP and RPPR
---------------------------------------------------

Description
----------------
This file contains code written by Nathan Neuhaus in connection with the graduate 
research supervised by Dr. Boris Kovalerchuk for Central Washington University, on
the Master's Thesis: Toward Efficient Automation of Interpretable Machine Learning
with Boosting, by Nathan Neuhaus. 

Implemented within this software are two novel Machine Learning algorithms, based
off the Master's Thesis: Toward Efficient Automation of Interpretable Machine 
Learning with Boosting, by Nathan Neuhaus. These algorithms are called the 
Dominance Classifier Predictor (DCP) algorithm, and also the Reverse Prediction 
Pattern Recognition boosting algorithm. 

Achievements
----------------
The DCP algorithm is the most accurate Interpretable Machine Learning algorithm
known to be tested on the attached benchmark datasets: Heart Disease (14), 
Wisconsin Breast Cancer (11), Wisconsin Breast Cancer (32). 

The RPPR boosting algorithm, which must be used in conjunction with DCP, is the 
most accurate Interpretable Machine Learning algorithm on the aforementioned 
datasets mentioned and is the first Interpretable Machine Learning algorithm to 
reach the accuracy of black-box models such as Artificial Neural Networks (ANNs) 
and Support Vector Machines (SVMs).

File Contents 
----------------
1. dcprpprkfold.c 	- the code for DCP, RPPR, using k-fold cross validation
2. data-heart-14.txt 	- Heart Disease dataset referenced in codebase
3. data-iris-5.txt 	- Iris dataset referenced in codebase
4. data-wbc-11.txt 	- Wisconsin Breast Cancer dataset referenced codebase
5. data-wbc-32.txt 	- Wisconsin Breast Cancer dataset referenced codebase
6. structures.h 	- Data structures used in dcprpprkfold.c
7. structures_svg.h 	- Export to SVG-image used in dcprpprkfold.c
8. readme.txt		- You are here	
