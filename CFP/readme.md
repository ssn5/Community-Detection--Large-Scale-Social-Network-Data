# Compilation 
## We ask that you open the CFP folder in a docker container. The dockerfile is the same one used in cs225. Cd into the build directory to make and run the main and the test files

# File Organization
## Report
  The report is a pdf file in the CFP folder
  All the essential files (for graph computation) are in the src folder
  The main file is in the entry folder. The user can run each graph algorithm separately on a smaller dataset, or they can run the entire project code.
  
  The graph algorithms are run on a small adjacency matrix present in the main file. Users can change that if they so wish. The project code uses the git dataset
  present in the git-data folder. We request the user not to touch those files. Instead, in the main file they can change dijkstra's starting point (when running
  the entire project code) to some other vertex.
  
  The test suite comprises of 2 tests - one for each graphing algorithm. The first test case is a smaller adjacency matrix, and the second one is a larger one.
  To change these conditions the user may cd into the tests folder and manipulate the tests
  
