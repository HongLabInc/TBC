#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME		41
#define MAX_PATIENTS	100

int main()
{
	/*
	Patient
	- name	 (string)
	- height (cm)
	- weight (kg)
	*/

	char name1[MAX_NAME], name2[MAX_NAME], name3[MAX_NAME];	// and more
	float height1, height2, height3;// ... and more
	float weight1, weight2, weight3;// ... and more

	strcpy(name1, "John Wick");
	height1 = 180;
	weight1 = 90;

	printf("%s %f %f\n", name1, height1, weight1);

	/* Arrays */
	char names[MAX_PATIENTS][MAX_NAME];
	float heights[MAX_PATIENTS];
	float weights[MAX_PATIENTS];

	strcpy(names[0], "John Wick");
	heights[0] = 180.0f;
	weights[0] = 90.0f;

	printf("%s %f %f\n", names[0], heights[0], weights[0]);

	/* Dynamic Arrays */

	char* names_da = (char*)malloc(sizeof(char) * MAX_NAME * MAX_PATIENTS);
	float* heights_da = (float*)malloc(sizeof(float) * MAX_PATIENTS);
	float* weights_da = (float*)malloc(sizeof(float) * MAX_PATIENTS);

	// Do we need to allocate large memory from the beginning?

	free(names_da);
	free(heights_da);
	free(weights_da);

	/* Structures */

	struct Patient{
		char name[MAX_NAME];
		float height;
		float weight;
		int age;
	};

	struct Patient p1, p2, p3;
	
	strcpy(p1.name, "John Wick");
	p1.height = 180;
	p1.weight = 90;

	strcpy(p2.name, "Dwayne Johnson");
	p2.height = 180;
	p2.weight = 120;

	// ...

	printf("%s %f %f\n", p2.name, p2.height, p2.weight);

	/* Arrays of Structures */

	struct Patient patients[MAX_PATIENTS] = { {"John Wick", 180, 90}, };
	printf("%s %f %f\n", patients[0].name, patients[0].height, patients[0].weight);

	/* Dynamic Arrays of Structures */

	struct Patient* patients_da = (struct Patient*) malloc(sizeof(struct Patient) * MAX_PATIENTS);

	free(patients_da);

	/*
		Data Structures
	*/

	/* Linked list

				p1 -> p2 -> p3
	Remove p2:	p1 -> p3
	Insert p4:	p1 -> p4 -> p3

	*/

	/* Tree 

			p1
		   /  \
		 p2    p3
	            \
				 p4
	*/

	/* Object-Oriented Programming
	
	struct Patient {
		char name[MAX_NAME];
		float height;
		float weight;
	};

	void print(const struct Patient* p)
	{
		printf("%s %f %f\n", p->name, p->height, p->weight);
	}

	// Data + Functions ?

	*/

	/* Data-Oriented Programming */

	return 0;
}
