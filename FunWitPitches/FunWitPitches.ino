/*
*   Author: Chet Udell, 2023
*   Example calculates MIDI pitch frequencies for playback on speaker
*   Uses a 2D array to store MIDI-duration in millisecond pairs to form a Melody
*   Use a for loop to sequentially play through the melody array
*/

#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

float midi[127];
int A_four = 440; // a is 440 hz...

// Arrays to store Scale MIDI pitch sequence
int c_major[8] = {60, 62, 64, 65, 67, 69, 71, 72}; // c_major scale on C4
int c_minor[8] = {60, 62, 63, 65, 67, 68, 70, 72}; // c_minor scale on C4

// Example of 2D Array
// First number is how many notes your melody will play
// Second number is how many elements of data will be stored for each note, 2 (MIDI pitch, Duration in milliseconds)
int song[6][2] = {
    {55, 200},  // song[0][0]], song[0][1]]
    {55, 200},  // song[1][0]], song[1][1]]
    {57, 400},  // song[2][0]], song[2][1]]
    {55, 400},  // song[3][0]], song[3][1]]
    {60, 400},  // song[4][0]], song[4][1]]
    {59, 600},  // song[5][0]], song[5][1]]
//  {127, 200},  // 127 will result in a frequency too high for the speaker to play, resulting in silence. You can use this as a "rest" or blank space in your melody
  };

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  generateMIDI(); // Custom function for calculating and storing the frequency value associated for each MIDI pitch number
}

void loop() {

  // Step through 2D array, setting 
  for(int i = 0; i < sizeof(song) / sizeof(song[0]); i++) // Calculate how many rows are in the array using: sizeof(song) / sizeof(song[0])
  {
    CircuitPlayground.playTone(midi[song[i][0]], song[i][1]);
    Serial.println(midi[song[i][0]]);
    delay(1);
  }
  
  delay(500); // End of Phrase

   // Add a for loop that plays 8 random notes from the c_major scale array, at random durations of 100, 200, 300, or 400 ms
  for(int i = 0; i < sizeof(c_major) / sizeof(int); i++) // Calculate how many rows are in the array using: sizeof(array) / sizeof(array[0])
  {
    int randomIndex = random(sizeof(c_major) / sizeof(int));  // Create a random number between 0 and size of scale array-1
    int randomDur = random(1,4);
    CircuitPlayground.playTone(midi[c_major[randomIndex]], randomDur*100); // note randomly from scale array, play random duration of 100, 200, 300, or 400
    Serial.println(midi[c_major[randomIndex]]);
    delay(1);
  }
  
  delay(500); // End of Phrase
}

void generateMIDI()
{
  for (int x = 0; x < 127; ++x)
  {
    midi[x] = (A_four / 32.0) * pow(2.0, ((x - 9.0) / 12.0));
    Serial.println(midi[x]);
  }
}

void CowBell(int awesomeness)
{
    int x = awesomeness;
}