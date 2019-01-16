//
//  main.cpp skeleton
//  lab3
//
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "shape.h"

// This is the shape array, to be dynamically allocated
shape** shapesArray;

// The number of shapes in the database, to be incremented 
// everytime a shape is successfully created
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);   // Get a line from standard input

    while (!cin.eof()) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so the flags are cleared
        stringstream lineStream (line);

        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here
        int c = -1;
        
        for (int i = 0; i < NUM_KEYWORDS; i++) {
            if (command == keyWordsList[i]) {
                c = i;
            }
        }
        
        if (c == -1) { //invalid command
            cout << "Error: invalid command" << endl;
        }
        
        else if (c == 1) { //maxShapes command
            int value;
            int inputs = 0;
            do {
                lineStream >> value;
                if (lineStream.fail()) {
                    if (lineStream.eof()) {
                        cout << "Error: too few arguments" << endl;
                    }
                    else {
                        cout << "Error: invalid argument" << endl;
                    }
                }
                inputs++;
            } while (!lineStream.eof());
            if (inputs > 1) {
                cout << "Error: too many arguments" << endl;
            }
            else {
                max_shapes = value;
                shapesArray = new shape *[max_shapes];
                for (int i = 0; i < max_shapes; i++) {
                    shapesArray[i] =  NULL;
                }
                cout << "New database: max shapes is " << max_shapes << endl;
            }
        }
        
        else if (c == 2) { //create command
            int x_loc, y_loc, x_sz, y_sz;
            string name, type;
            int inputs = 0;
            bool errorDetected = false;
            do {
                if (inputs == 0) { //check name argument
                    lineStream >> name;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else if (name == keyWordsList[0] || name == keyWordsList[1] || name == keyWordsList[2] || name == keyWordsList[3] || 
                            name == keyWordsList[4] || name == keyWordsList[5] || name == keyWordsList[6] || name == shapeTypesList[0] ||
                            name == shapeTypesList[1] || name == shapeTypesList[2]) {
                        cout << "Error: invalid shape name" << endl;
                        errorDetected = true;
                    }
                    else {
                        int i = 0;
                        bool nameExists = false;
                        while (i < shapeCount && nameExists == false) {
                            if (name == shapesArray[i]->getName()) {
                                nameExists = true;
                            }
                            i++;
                        }
                        if (nameExists) {
                            cout << "Error: shape " << name << " exists" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else if (inputs == 1) { //check type argument
                    lineStream >> type;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else {
                        if (!(type == shapeTypesList[0] || type == shapeTypesList[1] || type == shapeTypesList[2])) {
                            cout << "Error: invalid shape type" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else if (inputs == 2) { // check x_location argument
                    lineStream >> x_loc;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else {
                        if (x_loc < 0) {
                            cout << "Error: invalid value" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else if (inputs == 3) { // check y_location argument
                    lineStream >> y_loc;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else {
                        if (y_loc < 0) {
                            cout << "Error: invalid value" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else if (inputs == 4) { // check x_size argument
                    lineStream >> x_sz;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else {
                        if (x_sz < 1) {
                            cout << "Error: invalid value" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else if (inputs == 5) { // check y_size argument
                    lineStream >> y_sz;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else {
                        if (y_sz < 1) {
                            cout << "Error: invalid value" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else { //too many inputs
                    lineStream >> skipws;
                    if (!lineStream.eof()) {
                        cout << "Error: too many arguments" << endl;
                        errorDetected = true;
                    }
                    else {
                        break;
                    }
                }
            } while (!errorDetected);
            
            if (!errorDetected) {
                if (!(shapeCount < max_shapes)) { //shape array full
                    cout << "Error: shape array is full" << endl;
                }
                else { //create new shape
                    if (shapesArray[shapeCount] == NULL) {
                        shapesArray[shapeCount] = new shape(name, type, x_loc, y_loc, x_sz, y_sz);
                        shapeCount++;
                    }
                    cout << "Created " << name << ": " << type << " " << x_loc << " " << y_loc << " " << x_sz << " " << y_sz << endl;
                }
            }
        }
        
        else if (c == 3) { //move command
            string name;
            int x_loc, y_loc;
            int inputs = 0;
            bool errorDetected = false;
            do {
                if (inputs == 0) { //check name argument
                    lineStream >> name;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else if (name == shapeTypesList[0] || name == shapeTypesList[1] || name == shapeTypesList[2]) {
                        cout << "Error: invalid shape name" << endl;
                        errorDetected = true;
                    }
                    else {
                        int i = 0;
                        bool nameExists = false;
                        while (i < shapeCount && nameExists == false) {
                            if (name == shapesArray[i]->getName()) {
                                nameExists = true;
                            }
                            i++;
                        }
                        if (!nameExists) {
                            cout << "Error: shape " << name << " not found" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else if (inputs == 1) { //check x_location argument
                    lineStream >> x_loc;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else {
                        if (x_loc < 0) {
                            cout << "Error: invalid value" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else if (inputs == 2) { // check y_location argument
                    lineStream >> y_loc;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else {
                        if (y_loc < 0) {
                            cout << "Error: invalid value" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else { //too many inputs
                    lineStream >> skipws;
                    if (!lineStream.eof()) {
                        cout << "Error: too many arguments" << endl;
                        errorDetected = true;
                    }
                    else {
                        break;
                    }
                }
            } while (!errorDetected);
            if (!errorDetected) {
                for (int index = 0; index < shapeCount; index++) {
                    if (name == shapesArray[index]->getName()) {
                        shapesArray[index]->setXlocation(x_loc);
                        shapesArray[index]->setYlocation(y_loc);
                        cout << "Moved " << name << " to " << x_loc << " " << y_loc << endl;
                    }
                }
            }
        }
        
        else if (c == 4) { //rotate command
            int angle;
            string name;
            int inputs = 0;
            bool errorDetected = false;
            do {
                if (inputs == 0) { //check name argument
                    lineStream >> name;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else if (name == shapeTypesList[0] || name == shapeTypesList[1] || name == shapeTypesList[2]) {
                        cout << "Error: invalid shape name" << endl;
                        errorDetected = true;
                    }
                    else {
                        int i = 0;
                        bool nameExists = false;
                        while (i < shapeCount && nameExists == false) {
                            if (name == shapesArray[i]->getName()) {
                                nameExists = true;
                            }
                            i++;
                        }
                        if (!nameExists) {
                            cout << "Error: shape " << name << " not found" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else if (inputs == 1) { //check angle argument
                    lineStream >> angle;
                    if (lineStream.fail()) {
                        if (lineStream.eof()) {
                            cout << "Error: too few arguments" << endl;
                            errorDetected = true;
                        }
                        else {
                            cout << "Error: invalid argument" << endl;
                            errorDetected = true;
                        }
                    }
                    else {
                        if (angle < 0 || angle > 360) {
                            cout << "Error: invalid value" << endl;
                            errorDetected = true;
                        }
                        else {
                            inputs++;
                        }
                    }
                }
                else {
                    lineStream >> skipws;
                    if (!lineStream.eof()) {
                        cout << "Error: too many arguments" << endl;
                        errorDetected = true;
                    }
                    else {
                        break;
                    }
                }
            } while (!errorDetected);
            if (!errorDetected) {
                for (int index = 0; index < shapeCount; index++) {
                    if (name == shapesArray[index]->getName()) {
                        shapesArray[index]->setRotate(angle);
                        cout << "Rotated " << name << " by " << angle << " degrees" << endl;
                    }
                }
            }
        }
        
        else if (c == 5) { //draw command
            string name;
            lineStream >> name;
            if (lineStream.fail()) {
                if (lineStream.eof()) {
                    cout << "Error: too few arguments" << endl;
                }
                else {
                    cout << "Error: invalid argument" << endl;
                }
            }
            else {
                if (name == shapeTypesList[0] || name == shapeTypesList[1] || name == shapeTypesList[2]) {
                    cout << "Error: invalid shape name" << endl;
                }
                else {
                    int i = 0;
                    bool nameExists = false;
                    while (i < shapeCount && nameExists == false) {
                        if (name == shapesArray[i]->getName()) {
                            nameExists = true;
                        }
                        i++;
                    }
                    if (!nameExists && name != keyWordsList[0]) {
                        cout << "Error: shape " << name << " not found" << endl;
                    }
                    else {
                        lineStream >> skipws;
                        if (!lineStream.eof()) {
                            cout << "Error: too many arguments" << endl;
                        }
                        else {
                            if (name != keyWordsList[0]) { //one shape
                                for (int index = 0; index < shapeCount; index++) {
                                    if (name == shapesArray[index]->getName()) {
                                        cout << "Drew " << name << endl;
                                        shapesArray[index]->draw();
                                        break;
                                    }
                                }
                            }
                            else { //all shapes
                                cout << "Drew all shapes" << endl;
                                for (int j = 0; j < shapeCount; j++) {
                                    shapesArray[j]->draw();
                                }
                            }
                        }
                    }
                }
            }
        }
        
        else if (c == 6) { //delete command
            string name;
            lineStream >> name;
            if (lineStream.fail()) {
                if (lineStream.eof()) {
                    cout << "Error: too few arguments" << endl;
                }
                else {
                    cout << "Error: invalid argument" << endl;
                }
            }
            else {
                if (name == shapeTypesList[0] || name == shapeTypesList[1] || name == shapeTypesList[2]) {
                    cout << "Error: invalid shape name" << endl;
                }
                else {
                    int i = 0;
                    bool nameExists = false;
                    while (i < shapeCount && nameExists == false) {
                        if (name == shapesArray[i]->getName()) {
                            nameExists = true;
                        }
                        i++;
                    }
                    if (!nameExists && (name != keyWordsList[0])) {
                        cout << "Error: shape " << name << " not found" << endl;
                    }
                    else {
                        lineStream >> skipws;
                        if (!lineStream.eof()) {
                            cout << "Error: too many arguments" << endl;
                        }
                        else {
                            if (name != keyWordsList[0]) { //one shape
                                for (int i = 0; i < max_shapes; i++) {
                                    if (name == shapesArray[i]->getName()) {
                                        delete shapesArray[i];
                                        shapesArray[i] = NULL;
                                        shapeCount--;
                                        break;
                                    }
                                }
                                cout << "Deleted shape " << name << endl;
                            }
                            else { //all shapes
                                for (int j = 0; j < max_shapes; j++) {
                                    delete shapesArray[j];
                                    shapesArray[j] = NULL;
                                    shapeCount = 0;
                                }
                                cout << "Deleted: all shapes" << endl;
                            }
                        }
                    }
                }
            }
        }
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line
        
    }  // End input loop until EOF.
    
    return 0;
}

