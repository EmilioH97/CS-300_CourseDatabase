//============================================================================
// Name        : Project2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

void DisplayMenu() {

	cout << "Welcome to the Course Planner" << endl << endl;
	cout << "1. Load Data Structure" << endl;
	cout << "2. Print Course List" << endl;
	cout << "3. Print Course" << endl;
	cout << "9. Exit" << endl << endl;
	cout << "What would you like to do?";

}

struct Courses {
	string courseId;
	string courseName;
	vector<string> preRequisite;
};

struct Node {
	Course course;
	Node* left;
	Node* right;

	Node() {
		left = nullptr;
		right = nullptr;
	}
	Node(Course aCourse): Node() {
		this->course = aCourse;
	}
};

class BinarySearchTree {

private:
	void Destruct(Node* node);

public:
	Node* root;
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void Insert(BinarySearchTree* Tree, Node* node);
	void Search(string courseId);
	void PrintCourse(Node* node);
};

BinarySearchTree::BinarySearchTree() {
	Destruct(root);
}

void BinarySearchTree::Destruct(NOde* node) {
	if (node != nullptr) {
		Destruct(node->left);
		node->left = nullptr;
		Destruct(node->right);
		node->right = nullptr;
		delete node;
	}
};

void BinarySearchTree::Search(string courseId) {
	Node* currentNode = root;

	while (current != nullptr) {
		if (currentNode->course.courseId == courseId) {
			cout << currentNode->course.courseId << ",";
			cout << currentNode->course.courseName;
			cout << endl;
			cout << "Prerequisites: ";

			for (string preRequisite : currentNode->course.preRequisite) {
				if (preRequisite == currentNode->course.preRequisite.back()) {
					cout << preRequisite << endl;
				}
				else {
					cout << preRequisite << ",";
				}
			}
			return;
		}

		else if (courseId < currentNode->course.courseId) {
			if (currentNode->left != nullptr) {
				currentNode = currentNode->left;
			}
		}

		else {
			currentNode = current->right;
		}
	}
	cout << "Course " << courseId << "not found." << endl;
	return;
}

void BinarySearchTree::Insert(BinarySearchTree* tree, Node* node) {

	if (tree->root == nullptr) {
		tree->root = node;
	}

	else {
		Node* curr = tree->root;
		while (curr != nullptr) {

			if (node->course.courseId < curr->course.courseId) {

				if (curr->left == nullptr) {
					curr->left = node;
					curr = nullptr;
				}

				else {
					curr = curr->left;
				}
			}

			else {

				if (curr->right == nulptr) {
					curr->right = node;
					curr = nullptr;
				}

				else {
					curr = curr->right;
				}
			}
		}
	}
}

void BinarySearchTree::PrintCourse(Node* node) {
	if (node == nullptr) {
		return;
	}

	PrintCourse(node->left);
	cout << node->course.courseId << ", ";
	cout << node->course.courseName << endl;
	PrintCourse(node->right);
};

void loadCourse(string filename, BinarySearchTree* bst) {
	ifstrea file(filename);
	if (file.is_open()) {
		cout << "File loaded." << endl;
		int num;
		string line;
		string word;

		while (getline(file, line)) {
			num = 0;
			Node* node = new Node();
			stringstream str(line);

			while (num < 2) {
				getline(str, word, ",");
				if (num == 0) {
					node->course.courseId = word;
				}
				else {
					node->course.courseName = word;
				}
				num++
			}
			while (getkine(str, word, ",")) {
				nodecourse.preRequisite.push_back(word);
			}
			bst->Insert(bst, node);
		}
	}
	else {
		cout << "File error, please try again." << endl;
		return;
	}
}

void main() {
	BinarySearchTree* bst = new BinarySearchTree();

	string fileChoice;
	string courseChoice;

	int userInput = 0;
	cout << "Welcome to the course planner." << endl << endl;

	while (userInput != 9) {
		DisplayMenu();
		cin >> userInput;

		switch (userInput) {
		case 1:
			cout << endl;
			cout << "What file would you like to load?";
			cin >> fileChoice;

			loadCourse(fileChoice, bst);
			cout << endl;
			break;

		case 2:
			cout << endl;
			bst->PrintCourse(bst->root);
			cout << endl;
			break;

		case 3:
			cout << endl;
			cout << "What course do you want to learn about?";
			cin >> courseChoice;
			cout << endl;

			std::transform(courseChoice.begin(), courseChoice.end(), courseChoice.begin(), ::toupper);
			bst->Search(courseChoice);

			cout << endl;
			break;

		case 9:
			cout << "Thank you for using the course planner!" << endl;
			break;

		default:
			cout << userInput << " is not a valid option. " << endl << endl;
			break;
		}
	}
}