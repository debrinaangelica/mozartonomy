#include <TimeLib.h>

// Maximum number of notes we can record
const int MAX_NOTES = 128;

// Global music variables
int bpm = 88;
int last_record_notes[MAX_NOTES];
int last_record_durations[MAX_NOTES];
int last_record_rest[MAX_NOTES];
int num_notes = 0;

// Three main buttons
int RECORD = A1;
int STOP = A2;
int PLAY = A3;

// Digital input pins of the buttons
const int buzzer = A7;
const int led_pin = A5;

// Notes
const int c = 2;
const int c_s = 3;
const int d = 4;
const int d_s = 5;
const int e = 6;
const int f = 7;
const int f_s = 8;
const int g = 9;
const int g_s = 10;
const int a = 11;
const int a_s = 12;
const int b = 13;

// Digital output pins of solenoids
const int c_sol = 22;
const int c_s_sol = 23;
const int d_sol = 24;
const int d_s_sol = 25;
const int e_sol = 26;
const int f_sol = 27;
const int f_s_sol = 28;
const int g_sol = 29;
const int g_s_sol = 30;
const int a_sol = 31;
const int a_s_sol = 32;
const int b_sol = 33;


// Frequency of solenoids
int c_note = 524;
int c_s_note = 554;
int d_note = 588;
int d_s_note = 622;
int e_note = 660;
int f_note = 698;
int f_s_note = 740;
int g_note = 784;
int g_s_note = 830;
int a_note = 880;
int a_s_note = 932;
int b_note = 988;

// Function to record whatever the user plays
void record() {
  Serial.println("inside record");
  // Turn on LED to signify record
  digitalWrite(led_pin, HIGH);
  int note_count = 0;
  num_notes = 0;
  unsigned long last_time = millis();
  // When the STOP button has not been pressed and when we did not run out of memory

  while (1) {
    if (digitalRead(STOP) || note_count >= MAX_NOTES) {
      break;
    }
    if (digitalRead(c)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: C");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(c)) {
        tone(buzzer, c_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = c;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else if (digitalRead(c_s)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: C#");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(c_s)) {
        tone(buzzer, c_s_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = c_s;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else if (digitalRead(d)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: D");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(d)) {
        tone(buzzer, d_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = d;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else if (digitalRead(d_s)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: D#");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(d_s)) {
        tone(buzzer, d_s_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = d_s;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);

    } else if (digitalRead(e)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: E");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(e)) {
        tone(buzzer, e_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = e;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else if (digitalRead(f)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: F");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(f)) {
        tone(buzzer, f_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = f;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else if (digitalRead(f_s)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: F#");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(f_s)) {
        tone(buzzer, f_s_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = f_s;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else if (digitalRead(g)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: G");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(g)) {
        tone(buzzer, g_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = g;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else if (digitalRead(g_s)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: G#");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(g_s)) {
        tone(buzzer, g_s_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = g_s;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else if (digitalRead(a)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: A");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(a)) {
        tone(buzzer, a_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = a;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else if (digitalRead(a_s)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: A#");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(a_s)) {
        tone(buzzer, a_s_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = a_s;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    }  else if (digitalRead(b)) {
      // calculate the rest (if this isn't the first note played)
      Serial.println("Button pressed: B");
      unsigned long note_start = millis();

      // If the number of notes is more than 1
      if (note_count - 1 >= 0) {
        last_record_rest[note_count - 1] = note_start - last_time;
        Serial.print("Rest: ");
        Serial.println(last_record_rest[note_count - 1]);
      }

      // measure how long the note is pressed for
      while (digitalRead(b)) {
        tone(buzzer, b_note);
      }
      unsigned long note_end = millis();
      last_record_notes[note_count] = b;
      last_record_durations[note_count] = note_end - note_start;
      last_time = note_end;
      Serial.print("Duration: ");
      Serial.println(last_record_durations[note_count]);
      note_count += 1;
      Serial.println(note_count);
    } else {
    noTone(buzzer);
  }

  } 
  num_notes = note_count;
  digitalWrite(led_pin, LOW);
  Serial.println("Record done!");
}

// Function to play note on the buzzer
void play_note(int note, int play_duration, int rest_duration) {
  if (note == c) {
    Serial.println("Playing C");
    digitalWrite(c_sol, HIGH);
    tone(buzzer, c_note, play_duration);
    delay(play_duration);
    digitalWrite(c_sol, LOW);
    delay(rest_duration);
  } else if (note == c_s) {
    Serial.println("Playing C#");
    digitalWrite(c_s_sol, HIGH);
    tone(buzzer, c_s_note, play_duration);
    delay(play_duration);
    digitalWrite(c_s_sol, LOW);
    delay(rest_duration);
  } else if (note == d) {
    Serial.println("Playing D");
    digitalWrite(d_sol, HIGH);
    tone(buzzer, d_note, play_duration);
    delay(play_duration);
    digitalWrite(d_sol, LOW);
    delay(rest_duration);
  } else if (note == d_s) {
    Serial.println("Playing D#");
    digitalWrite(d_s_sol, HIGH);
    tone(buzzer, d_s_note, play_duration);
    delay(play_duration);
    digitalWrite(d_s_sol, LOW);
    delay(rest_duration);
  } else if (note == e) {
    Serial.println("Playing E");
    digitalWrite(e_sol, HIGH);
    tone(buzzer, e_note, play_duration);
    delay(play_duration);
    digitalWrite(e_sol, LOW);
    delay(rest_duration);
  } else if (note == f) {
    Serial.println("Playing F");
    digitalWrite(f_sol, HIGH);
    tone(buzzer, f_note, play_duration);
    delay(play_duration);
    digitalWrite(f_sol, LOW);
    delay(rest_duration);
  } else if (note == f_s) {
    Serial.println("Playing F#");
    digitalWrite(f_s_sol, HIGH);
    tone(buzzer, f_s_note, play_duration);
    delay(play_duration);
    digitalWrite(f_s_sol, LOW);
    delay(rest_duration);
  } else if (note == g) {
    Serial.println("Playing G");
    digitalWrite(g_sol, HIGH);
    tone(buzzer, g_note, play_duration);
    delay(play_duration);
    digitalWrite(g_sol, LOW);
    delay(rest_duration);
  } else if (note == g_s) {
    Serial.println("Playing G#");
    digitalWrite(g_s_sol, HIGH);
    tone(buzzer, g_s_note, play_duration);
    delay(play_duration);
    digitalWrite(g_s_sol, LOW);
    delay(rest_duration);
  } else if (note == a) {
    Serial.println("Playing A");
    digitalWrite(a_sol, HIGH);
    tone(buzzer, a_note, play_duration);
    delay(play_duration);
    digitalWrite(a_sol, LOW);
    delay(rest_duration);
  } else if (note == a_s) {
    Serial.println("Playing A#");
    digitalWrite(a_s_sol, HIGH);
    tone(buzzer, a_s_note, play_duration);
    delay(play_duration);
    digitalWrite(a_s_sol, LOW);
    delay(rest_duration);
  } else if (note == b) {
    Serial.println("Playing B");
    digitalWrite(b_sol, HIGH);
    tone(buzzer, b_note, play_duration);
    delay(play_duration);
    digitalWrite(b_sol, LOW);
    delay(rest_duration);
  }
}



void setup() {
  // Initializing buzzer
  pinMode(buzzer, OUTPUT);
  pinMode(led_pin, OUTPUT);
  // Initializing the Record, Stop, and Playback buttons
  pinMode(RECORD, INPUT);
  pinMode(STOP, INPUT);
  pinMode(PLAY, INPUT);
  // Initializing the buttons
  pinMode(c, INPUT);
  pinMode(c_s, INPUT);
  pinMode(d, INPUT);
  pinMode(d_s, INPUT);
  pinMode(e, INPUT);
  pinMode(f, INPUT);
  pinMode(f_s, INPUT);
  pinMode(g, INPUT);
  pinMode(g_s, INPUT);
  pinMode(a, INPUT);
  pinMode(a_s, INPUT);
  pinMode(b, INPUT);
  pinMode(c_sol, OUTPUT);
  pinMode(c_s_sol, OUTPUT);
  pinMode(d_sol, OUTPUT);
  pinMode(d_s_sol, OUTPUT);
  pinMode(e_sol, OUTPUT);
  pinMode(f_sol, OUTPUT);
  pinMode(f_s_sol, OUTPUT);
  pinMode(g_sol, OUTPUT);
  pinMode(g_s_sol, OUTPUT);
  pinMode(a_sol, OUTPUT);
  pinMode(a_s_sol, OUTPUT);
  pinMode(b_sol, OUTPUT);
  Serial.begin(9600);
}

// Function to playback whatever the user records
void playback() {
  Serial.println("Playing back...");
  delay(1000);
  // No need to set the pinModes yet because we might use 2 arduinos
  for (int i = 0; i < num_notes; i++) {
    int curr_note = last_record_notes[i];
    int curr_duration = last_record_durations[i];
    int curr_rest = last_record_rest[i];
    // Play the solenoid for the current note and the current duration
    Serial.print("Curr Note: ");
    Serial.println(curr_note);
    play_note(curr_note, curr_duration, curr_rest);
  }
}

void loop() {
  // If the record button is pressed
  if (digitalRead(RECORD)) {
    Serial.println("record");
    record();
  }
  // Playback
  if (digitalRead(PLAY)) {
    Serial.println("play");
    playback();
  }
  if (digitalRead(c)) {
    while(digitalRead(c)) {
      tone(buzzer, c_note);
    }
  } else if (digitalRead(c_s)) {
    while(digitalRead(c_s)) {
      tone(buzzer, c_s_note);
    }
  } else if (digitalRead(d)) {
    while(digitalRead(d)) {
      tone(buzzer, d_note);
    }
  } else if (digitalRead(d_s)) {
    while(digitalRead(d_s)) {
      tone(buzzer, d_s_note);
    }
  } else if (digitalRead(e)) {
    while(digitalRead(e)) {
      tone(buzzer, e_note);
    }
  } else if (digitalRead(f)) {
    while(digitalRead(f)) {
      tone(buzzer, f_note);
    }
  } else if (digitalRead(f_s)) {
    while(digitalRead(f_s)) {
      tone(buzzer, f_s_note);
    }
  } else if (digitalRead(g)) {
    while(digitalRead(g)) {
      tone(buzzer, g_note);
    }
  } else if (digitalRead(g_s)) {
    while(digitalRead(g_s)) {
      tone(buzzer, g_s_note);
    }
  } else if (digitalRead(a)) {
    while(digitalRead(a)) {
      tone(buzzer, a_note);
    }
  } else if (digitalRead(a_s)) {
    while(digitalRead(a_s)) {
      tone(buzzer, a_s_note);
    }
  } else if (digitalRead(b)) {
    Serial.println("b is presse");
    while(digitalRead(b)) {
      tone(buzzer, b_note);
    }
  }
  noTone(buzzer);
}
