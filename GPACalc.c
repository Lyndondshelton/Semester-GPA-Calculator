#include <stdio.h>
#include <stdlib.h>

int semCredits;
float totalQualityPoints, semGPA;
char grade;

void calcGrade(char grade, int credit){
    int gradeValue = 0;
    float qualityPoints;
    if(grade == 'a' || grade == 'A'){
            gradeValue = 4;
        }else if(grade == 'b' || grade == 'B'){
            gradeValue = 3;
        }else if(grade == 'c' || grade == 'C'){
            gradeValue = 2;
        }else if(grade == 'd' || grade == 'D'){
            gradeValue = 1;
        }else if(grade == 'f' || grade == 'F'){
            gradeValue = 0;
        }else{
            printf("%c is not a valid letter grade!", grade);
        }

    qualityPoints = gradeValue * credit;
    printf("Quality Points = %0.2f\n", qualityPoints);

    totalQualityPoints += qualityPoints;
    printf("Total Quality Points = %d\n", totalQualityPoints);
}

void startCalc(){
    int numClasses = 0;
    printf("How many classes are you taking this semester?\n");
    scanf("%d", &numClasses);

    for(int i=1; i < numClasses+1; i++){
        int credit = 0;
        printf("Class #%d credits: ", i);
        scanf("%d", &credit);
        semCredits += credit;
        printf("Semester Credits= %d\n", semCredits);

        printf("Expected Letter Grade for Class #%d:", i);
        scanf(" %c", &grade);

        calcGrade(grade, credit);
    }

    semGPA = totalQualityPoints / semCredits;
    printf("Your semester GPA is %0.2f ", semGPA);
}

int main(){

    startCalc();
    return 0;
}
