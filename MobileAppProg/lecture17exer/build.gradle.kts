// Top-level build file where you can add configuration options common to all sub-projects/modules.
buildscript {
    repositories {
        google()
    }
    dependencies {
//        val nav_version = "2.7.5"
        classpath("androidx.navigation:navigation-safe-args-gradle-plugin:2.7.5");
//        classpath ("android.arch.navigation:navigation-safe-args-gradle-plugin:2.4.2-alpha09")
    }
}

plugins {
    id("com.android.application") version "8.1.1" apply false
}