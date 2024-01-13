package com.mobileapp.lecture11exer;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;

import com.mobileapp.lecture11exer.databinding.FragmentWelcomeBinding;


public class WelcomeFragment extends Fragment {
    private FragmentWelcomeBinding binding;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        binding = FragmentWelcomeBinding.inflate(inflater, container, false);
        View view = binding.getRoot();
//        View view = inflater.inflate(R.layout.fragment_welcome, container, false);
        getActivity().setTitle("lecture14exer");



//        Button startButton = view.findViewById(R.id.startButton);


        binding.startButton.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                Navigation.findNavController(view).navigate(R.id.action_welcomeFragment_to_messageFragment);
            }
        });

        // Inflate the layout for this fragment
        return view;
    }
    @Override
    public void onDestroyView() {
        super.onDestroyView();
        binding = null;
    }
}