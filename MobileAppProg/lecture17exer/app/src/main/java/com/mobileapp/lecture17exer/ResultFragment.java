package com.mobileapp.lecture17exer;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.lifecycle.ViewModelProvider;
import androidx.navigation.Navigation;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import com.mobileapp.lecture17exer.databinding.FragmentGameBinding;
import com.mobileapp.lecture17exer.databinding.FragmentResultBinding;

import java.util.Arrays;

public class ResultFragment extends Fragment {

    private GameViewModel gameViewModel;
    private FragmentResultBinding binding;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        binding = FragmentResultBinding.inflate(inflater, container, false);

        TextView resultText = binding.resultTextView;
        String message = ResultFragmentArgs.fromBundle(requireArguments()).getMessage();
        Button restartButton = binding.button2;
        View view = binding.getRoot();
        gameViewModel = new ViewModelProvider(this).get(GameViewModel.class);

        restartButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
//                gameViewModel.livesLeft = 8;
//                gameViewModel.gameLost = false;
//                gameViewModel.gameWon = false;
//                gameViewModel.blankWord = new StringBuilder("_ _ _ _ _ _ _ _");
                Navigation.findNavController(view).navigate(R.id.action_resultFragment_to_gameFragment);
            }
        });

        resultText.setText(message);
        // Inflate the layout for this fragment
        return view;
    }
}