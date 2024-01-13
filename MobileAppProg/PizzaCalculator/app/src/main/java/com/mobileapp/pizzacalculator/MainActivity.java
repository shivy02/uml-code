/***********************************************
 Author: Shivam Patel
 Date: 9/23/23
 Purpose: To create a calculator that calculates how much pizza is needed for guests
 What Learned: I learned how to use multiple inputs in order to calculate a value for the user.
 Sources of Help: Stack Overflow
 for help: tutors, web sites, lab assistants etc.>
 Time Spent: 1hr
 ***********************************************/
/*
Mobile App Development I -- COMP.4630 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and training as a practicing computing professional upon graduation. This practice is manifested in the University's Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will be dealt with as outlined therein. All programming assignments in this class are to be done by the student alone unless otherwise specified. No outside help is permitted except the instructor and approved tutors.

I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass Lowell academic code.

Date: 9/23/23
Name: Shivam Patel
*/
package com.mobileapp.pizzacalculator;
import androidx.appcompat.app.AppCompatActivity;
import android.annotation.SuppressLint;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button calcButton = findViewById(R.id.calcButton);

        calcButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v) {
                calculatePizza();
            }
        });
     }

     public void calculatePizza(){

         Spinner hungerLevel = findViewById(R.id.hungerLevel);
         EditText numGuests = findViewById(R.id.numGuests);
         TextView numPizza = findViewById(R.id.numPizza);

         String s = numGuests.getText().toString();
         String finalS = hungerLevel.getSelectedItem().toString();

         String x = "nothing";
         if(s.isEmpty()){
             numPizza.setText(x);
         }

         int numPeople = Integer.parseInt(s);
         int num1 = 0;
         switch (finalS) {
             case "Light":
                 num1 = 2;
                 break;
             case "Medium":
                 num1 = 3;
                 break;
             case "Ravenous":
                 num1 = 4;
                 break;
         }

         int numPiesNeeded = numPeople * num1;
         int totalPizza = (numPiesNeeded + 11) / 12;

         numPizza.setText(String.valueOf(totalPizza));
         System.out.println(totalPizza);
     }
}