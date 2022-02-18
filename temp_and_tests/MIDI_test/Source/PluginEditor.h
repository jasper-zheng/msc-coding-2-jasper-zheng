/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MIDI_testAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    MIDI_testAudioProcessorEditor (MIDI_testAudioProcessor&);
    ~MIDI_testAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MIDI_testAudioProcessor& audioProcessor;
    
    juce::Slider midiVolume; // [1]

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MIDI_testAudioProcessorEditor)
};
