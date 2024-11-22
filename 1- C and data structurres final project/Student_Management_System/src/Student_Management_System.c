/*============================================================================
 Name of project	: Student Management System
 Author      		: Mahmoud Esmat
 Date        		: 8/8/2024
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
typedef signed char		sint8;   	// 8-bit signed integer
typedef unsigned char   uint8;  	// 8-bit unsigned integer
typedef signed int      sint32;  	// 32-bit signed integer
typedef float    		float32;    // 32-bit signed float
enum bool{false, true};
uint8 flag = false; // Flag to indicate if an ID is already reserved or not
/*============================================================================*/
/*============================================================================*/
		/* -------Define a structure to represent the student's data------- */
struct student
{
	sint32 id;						// Student ID
	sint8 name[MAX_NAME_LENGTH];	// Student Name
	sint32 age;						// Student Age
	float32 gpa;					// Student GPA
};
/*============================================================================*/
/*============================================================================*/
		/* -------define a structure to represent a node in a linked list------- */
struct node
{
	struct student data;  		// Variable of type student (structure)
	struct node *next;			// pointer of type node (structure)
};
/*============================================================================*/
/*============================================================================*/
		/* -------Global pointer to the head of the linked list------- */
struct node *head = NULL;
/*============================================================================*/
/*============================================================================*/
		/* -------Function to input student data------- */
void scanStudent (struct student *ptr)
{
	struct node *current = head; // new pointer to node (structure)
	sint32 id; // to check if it's already reserved or not

	printf("Enter id: ");  fflush(stdout); // to enter id of new student
	scanf("%d", &id);

	while (current != NULL) // to check new id is reserved or not
	{
		if (id == current->data.id)
		{
			printf("This id is already reserved\n");
			flag = true; // to know this id is already reserved
			return; // to try again
		}
		current = current->next; // to Move to the next node
	}
	ptr->id = id; // Set the ID for the new student

	printf("Enter name: ");   fflush(stdout);
	scanf("%s", ptr->name); //to enter name of new student

	printf("Enter age: ");  fflush(stdout);
	scanf("%d", &(ptr->age)); // to enter age of new student
	printf("Enter GPA: ");  fflush(stdout);
	scanf("%f", &(ptr->gpa)); // to enter GPA of new student
	flag = false; // to reset flag
}
/*============================================================================*/
/*============================================================================*/
		/* -------Function to add a student to the linked list------- */
void addStudent (const struct student *const ptr)
{
	struct node *current = head; // new pointer to node (structure)

			/* Allocate memory for a new node */
	struct node *link = (struct node *)malloc(sizeof(struct node));
	if (link == NULL)
	{
		printf("Please try again");
		return;
	}

	/*
	 * Assign student data to the new node
	 * Because the pointer size is equal to the student size
	 * */
	link->data = *ptr;
	link->next = NULL;

	// for first node in linked list
	if (head == NULL)
	{
		head = link;
	}
	else
	{	// to add the new node at the end of the linked list
		while(current->next != NULL)
		{
			current = current->next; // to Move to the next node
		}
		current->next = link;
	}
	printf("----------------------------\n");
	printf("Student added successfully\n");
	printf("----------------------------\n");
}
/*============================================================================*/
/*============================================================================*/
		/* -------Function to display all students in linked list------- */
void displayStudents (void)
{	// to make sure this linked list not empty
	if(head == NULL)
	{
		printf("No students are present");
		return;
	}
	struct node *current = head;
	while (current != NULL)
	{	// Print student details
		printf("{ID: %d, ", current->data.id);
		printf("Name: %s, ", current->data.name);
		printf("Age: %d, ", current->data.age);
		printf("GPA: %.2f}\n", current->data.gpa);
		current = current->next; // to Move to the next node
	}
}
/*============================================================================*/
/*============================================================================*/
		/* -------Function to search for a student by ID------- */
void searchStudentByID(sint32 id)
{
	struct node *current = head;

	if(current == NULL) // to make sure this linked list not empty
	{
		printf("No students are present\n");
		return;
	}

	while(current != NULL)
	{
		if(current->data.id == id)
		{	// Print student details if ID matches
			printf("{ID: %d, ", current->data.id);
			printf("Name: %s, ", current->data.name);
			printf("Age: %d, ", current->data.age);
			printf("GPA: %.2f}\n", current->data.gpa);
			return;
		}
		current = current->next; // Move to the next node
	}
	printf("The student not found\n");
}
/*============================================================================*/
/*============================================================================*/
		/* -------Function to update student information------- */
void updateStudent(sint32 id)
{
	sint32 check_id; // to check id
	struct node *current = head;
	struct node *ptr = head;

	if(head == NULL) // to make sure this linked list not empty
	{
		printf("No students are present\n");
		return;
	}

	while(current != NULL)
	{
		if(current->data.id == id)
		{	// Enter id for new student and check if id reserved or not
			printf("Enter new id: ");  fflush(stdout);
			scanf("%d", &check_id); // to enter id of new student

			while (ptr != NULL) // to check new id is reserved or not
			{
				if (ptr->data.id == check_id)
				{
					printf("This id is already reserved\n");
					return; // to try again
				}
				ptr = ptr->next; // Move to the next node
			}
			// Update student information
			current->data.id = check_id;
			printf("Enter name: ");   fflush(stdout);
			scanf("%s", current->data.name); // to enter name of new student
			printf("Enter new age: ");  fflush(stdout);
			scanf("%d", &(current->data.age)); // to enter age of new student
			printf("Enter new GPA: ");  fflush(stdout);
			scanf("%f", &(current->data.gpa)); // to enter GPA of new student
			return;
		}
		current = current->next; // Move to the last node
	}

	printf("The student not found\n"); // if id not found in linked list

}
/*============================================================================*/
/*============================================================================*/
		/* -------Function to calculate the average GPA of all students------- */
float calculateAverageGPA(void)
{
	struct node *current = head;
	float32 average = false, sum = false;
	sint32 count = false;

	if(head == NULL) // to make sure this linked list not empty
	{
		return average;
	}

	while (current != NULL)
	{
		sum += current->data.gpa;
		count++;
		current = current->next; // to Move to the next node
	}
	average = sum / count; // Calculate average GPA
	return average;
}
/*============================================================================*/
/*============================================================================*/
		/* -------Function to search for the student with the highest GPA------- */
void searchHighestGPA(void)
{
	struct node *current = head;

	if(current == NULL) // to make sure this linked list not empty
	{
		printf("No students are present\n");
		return;
	}

	float32 highest = current->data.gpa; // Initialize highest GPA

	while (current != NULL)
	{
		if(highest < current->data.gpa) // check who is highest
		{
			highest = current->data.gpa;
		}
		current = current->next; // to Move to the next node
	}
	current = head; // to return to the first node

			/* -------This loop because more than one student can have the same GPA------- */
	while(current != NULL)
	{	// Print student(s) with the highest GPA
		if(current->data.gpa == highest)
		{
			printf("{ID: %d, ", current->data.id);
			printf("Name: %s, ", current->data.name);
			printf("Age: %d, ", current->data.age);
			printf("GPA: %.2f}\n", current->data.gpa);
			return;
		}
		current = current->next; // to Move to the next node
	}
}
/*============================================================================*/
/*============================================================================*/
		/* -------Function to delete a student by ID------- */
void deleteStudent(sint32 id)
{
	struct node *current = head;
	struct node *previous = head;

	if(current == NULL) // to make sure this linked list not empty
	{
		printf("No students are present\n");
		return;
	}

	if(current->data.id == id) // to check first node
	{
		head = current->next;
		free(current); // Free the memory of the deleted node
		printf("this student data is deleted successfully.\n");
		return;
	}
	current = current->next; // to make the current in second node

	while(current != NULL)// Find the student with the given ID
	{
		if(current->data.id == id)
		{
			previous->next = current->next;
			free(current); // Free the memory of the deleted node
			printf("this student data is deleted successfully.\n");
			return;
		}
		current = current->next;
		previous = previous->next;
	}
	printf("This is id not found\n");
}
/*============================================================================*/
/*============================================================================*/
				/* -------Main function------- */
int main(void)
{
	uint8 num;
	sint32 id;

	while (num != 8) // Main loop for enter or know all data by only run
	{
		printf("-----------------------------------------------\n");
		printf("1. Add student\n");
		printf("2. Display students\n");
		printf("3. Search student by ID\n");
		printf("4. Update student information\n");
		printf("5. Delete student\n");
		printf("6. Calculate average GPA\n");
		printf("7. Search for student with highest GPA\n");
		printf("8. Exit\n");
		printf("-----------------------------------------------\n");

		printf("Enter Choice: ");  fflush(stdout); // Get user's choice
		scanf("%d", &num);

		switch(num)
		{
		case 1:
			struct student *ptr = (struct student *)malloc(sizeof(struct student));
			if(ptr == NULL)
			{
				printf("please Try again"); fflush(stdout);
				return 0;
			}
			scanStudent(ptr);
			if(flag == false)
			{
				addStudent(ptr);
			}
			free(ptr); // Free memory after adding the student
			break;
		case 2:
			displayStudents();
			break;
		case 3:
			printf("Enter id of the student: ");  fflush(stdout);
			scanf("%d", &id);
			searchStudentByID(id);
			break;
		case 4:
			printf("Enter id of the student: ");  fflush(stdout);
			scanf("%d", &id);
			updateStudent(id);
			break;
		case 5:
			printf("Enter id of the student: ");  fflush(stdout);
			scanf("%d", &id);
			deleteStudent(id);
			break;
		case 6:
			printf("The average of GPA of all student is: %.2f\n", calculateAverageGPA());
			break;
		case 7:
			searchHighestGPA();
			break;
		default :
			printf("---------------Thanks---------------");
			return 0;
		}
	}
}
