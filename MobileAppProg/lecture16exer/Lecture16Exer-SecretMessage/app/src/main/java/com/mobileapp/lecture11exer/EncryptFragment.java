package com.mobileapp.lecture11exer;

import android.os.Bundle;

import androidx.fragment.app.Fragment;

import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

public class EncryptFragment extends Fragment {


    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        View view = inflater.inflate(R.layout.fragment_encrypt, container, false);
        getActivity().setTitle("Encrypt");
        TextView encryptedMessage = view.findViewById(R.id.encryptedMessage);

        String message = EncryptFragmentArgs.fromBundle(requireArguments()).getMessage();
        Log.d("DEBUG", message);
        String reversed = new StringBuilder(message).reverse().toString();




        encryptedMessage.setText(reversed);



        return view;
    }
}