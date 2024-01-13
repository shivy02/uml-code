package com.mobileapp.lecture11exer;

import android.os.Bundle;

import androidx.fragment.app.Fragment;
import androidx.navigation.Navigation;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;

public class MessageFragment extends Fragment {

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_message, container, false);

        Button encryptButton = view.findViewById(R.id.encryptButton);
        EditText editText = view.findViewById(R.id.editTextText);


        encryptButton.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View v) {
                String message = editText.getText().toString();
                MessageFragmentDirections.ActionMessageFragmentToEncryptFragment action = MessageFragmentDirections.actionMessageFragmentToEncryptFragment(message);
                Navigation.findNavController(view).navigate(action);

            }
        });

        // Inflate the layout for this fragment
        return view;
    }
}