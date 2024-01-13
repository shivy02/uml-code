/*
Mobile App Development I -- COMP.4630 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and training as a practicing computing
professional upon graduation. This practice is manifested in the
University's Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations
will be dealt with as outlined therein. All programming assignments
in this class are to be done by the student alone unless otherwise
specified. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and
was generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 11/06/2023
Name: Shivam Patel

 */
package com.mobileapp.lecture08exer;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.os.SystemClock;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.Chronometer;

import android.os.Bundle;

import com.mobileapp.lecture08exer.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {
    private boolean isStopwatchRunning = false;
    private boolean appJustStarted = true;
    private long offset = 0;
    private ActivityMainBinding binding;
    private Chronometer stopwatch;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        View view = binding.getRoot();
        setContentView(view);

        stopwatch = binding.chronometer;
//        Button startButton = findViewById(R.id.startButton);
//        Button pauseButton = findViewById(R.id.pauseButton);
//        Button resetButton = findViewById(R.id.resetButton);

        if (savedInstanceState != null) {
            // Restore the stopwatch state from the savedInstanceState bundle
            offset = savedInstanceState.getLong("offset");
            isStopwatchRunning = savedInstanceState.getBoolean("isStopwatchRunning");
            long chronometerBase = savedInstanceState.getLong("chronometerBase");

            if (isStopwatchRunning) {
                stopwatch.setBase(chronometerBase + SystemClock.elapsedRealtime() - offset);
                stopwatch.start();
            } else {
                stopwatch.setBase(SystemClock.elapsedRealtime() - offset);
            }
        }

        binding.startButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onRestart();
            }

        });

        binding.pauseButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (isStopwatchRunning) {
                    offset = SystemClock.elapsedRealtime() - stopwatch.getBase();
                    stopwatch.stop();
                    isStopwatchRunning = false;
                }
            }
        });

        binding.resetButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                stopwatch.setBase(SystemClock.elapsedRealtime());
                offset = 0;
                isStopwatchRunning = false;
            }
        });

    }

    @Override
    protected void onSaveInstanceState(Bundle savedInstanceState) {
        // Save the stopwatch state to the bundle
        savedInstanceState.putLong("offset", offset);
        savedInstanceState.putBoolean("isStopwatchRunning", isStopwatchRunning);
        savedInstanceState.putLong("chronometerBase", stopwatch.getBase());
        super.onSaveInstanceState(savedInstanceState);
    }

    @Override
    protected void onStart() {
        super.onStart();
//         start code
//        if (!isStopwatchRunning) {
//                Log.d("STOPWATCH_DEBUG", "im in here");
//                stopwatch.setBase(SystemClock.elapsedRealtime() - offset);
//                stopwatch.start();
//                isStopwatchRunning = true;
//
//        }
        Log.d("STOPWATCH_DEBUG", "in onStart()");
    }

    @Override
    protected void onResume() {
        super.onResume();
        if(isStopwatchRunning){
            stopwatch.setBase(SystemClock.elapsedRealtime() - offset);
            stopwatch.start();
            isStopwatchRunning = true;
        }
//        onRestart();
        Log.d("STOPWATCH_DEBUG", "in onResume()");
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Log.d("STOPWATCH_DEBUG", "in onRestart()");
        if(!isStopwatchRunning){
            stopwatch.setBase(SystemClock.elapsedRealtime() - offset);
            stopwatch.start();
            isStopwatchRunning = true;
        }

    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.d("STOPWATCH_DEBUG", "in onPause()");

    }

    @Override
    protected void onStop() {
        super.onStop();
        if(isStopwatchRunning) {
            stopwatch.stop();
            offset = SystemClock.elapsedRealtime() - stopwatch.getBase();
            isStopwatchRunning = false;
            Log.d("STOPWATCH_DEBUG", "in onStop()");
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d("STOPWATCH_DEBUG", "in onDestroy()");
    }

}