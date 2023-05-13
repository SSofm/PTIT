package com.sang.shoeapp.fragments;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;

import com.sang.shoeapp.MainActivity;
import com.sang.shoeapp.R;
import com.sang.shoeapp.model.User;
import com.sang.shoeapp.shared.DataLocalManager;

import org.w3c.dom.Text;

public class ProfileFragment extends Fragment {
    TextView usernameProfile;
    Button editProfile, signOut;
    ImageView backBtn;

    @SuppressLint("MissingInflatedId")
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.profile_fragment, container, false);
        usernameProfile = (TextView) view.findViewById(R.id.usernameProfile);
        editProfile = (Button) view.findViewById(R.id.editProfileBtn);
        backBtn = (ImageView) view.findViewById(R.id.backBtn);
        signOut = (Button) view.findViewById(R.id.signOutBtn);
        User user = DataLocalManager.getUser();
        if (user != null) {
            usernameProfile.setText(user.getUsername());
        }
        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        backBtn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goHome();
            }
        });

        editProfile.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goEditProfile();
            }
        });
        signOut.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ((MainActivity) getActivity()).goSignIn();
            }
        });
    }
}
