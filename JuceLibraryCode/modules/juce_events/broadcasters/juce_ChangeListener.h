/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2016 - ROLI Ltd.

   Permission is granted to use this software under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license/

   Permission to use, copy, modify, and/or distribute this software for any
   purpose with or without fee is hereby granted, provided that the above
   copyright notice and this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH REGARD
   TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND
   FITNESS. IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT,
   OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF
   USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
   TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
   OF THIS SOFTWARE.

   -----------------------------------------------------------------------------

   To release a closed-source product which uses other parts of JUCE not
   licensed under the ISC terms, commercial licenses are available: visit
   www.juce.com for more information.

  ==============================================================================
*/

#pragma once

class ChangeBroadcaster;

//==============================================================================
/**
    Receives change event callbacks that are sent out by a ChangeBroadcaster.

    A ChangeBroadcaster keeps a set of listeners to which it broadcasts a message when
    the ChangeBroadcaster::sendChangeMessage() method is called. A subclass of
    ChangeListener is used to receive these callbacks.

    Note that the major difference between an ActionListener and a ChangeListener
    is that for a ChangeListener, multiple changes will be coalesced into fewer
    callbacks, but ActionListeners perform one callback for every event posted.

    @see ChangeBroadcaster, ActionListener
*/
class JUCE_API  ChangeListener
{
public:
    /** Destructor. */
    virtual ~ChangeListener()  {}

    /** Your subclass should implement this method to receive the callback.
        @param source the ChangeBroadcaster that triggered the callback.
    */
    virtual void changeListenerCallback (ChangeBroadcaster* source) = 0;


    //==============================================================================
   #if JUCE_CATCH_DEPRECATED_CODE_MISUSE
    // This method's signature has changed to take a ChangeBroadcaster parameter - please update your code!
    private: virtual int changeListenerCallback (void*) { return 0; }
   #endif
};
