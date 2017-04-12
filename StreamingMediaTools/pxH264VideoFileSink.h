/**********
This library is free software; you can redistribute it and/or modify it under
the terms of the GNU Lesser General Public License as published by the
Free Software Foundation; either version 2.1 of the License, or (at your
option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)

This library is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
**********/
// "liveMedia"
// Copyright (c) 1996-2016 Live Networks, Inc.  All rights reserved.
// H.264 Video File Sinks
// C++ header

#ifndef _PX_H264_VIDEO_FILE_SINK_HH
#define _PX_H264_VIDEO_FILE_SINK_HH

#include "H264or5VideoFileSink.hh"

class CPxH264VideoFileSink: public H264or5VideoFileSink 
{
public:
  static CPxH264VideoFileSink* createNew(UsageEnvironment& env, char const* fileName,
				      char const* sPropParameterSetsStr = NULL,
      // "sPropParameterSetsStr" is an optional 'SDP format' string
      // (comma-separated Base64-encoded) representing SPS and/or PPS NAL-units
      // to prepend to the output
				      unsigned bufferSize = 100000,
				      Boolean oneFilePerFrame = False);
      // See "FileSink.hh" for a description of these parameters.

protected:
  CPxH264VideoFileSink(UsageEnvironment& env, FILE* fid,
		    char const* sPropParameterSetsStr,
		    unsigned bufferSize, char const* perFrameFileNamePrefix);
      // called only by createNew()
  virtual ~CPxH264VideoFileSink();

protected:
	virtual void afterGettingFrame(unsigned frameSize, unsigned numTruncatedBytes, struct timeval presentationTime);

private:
	CRITICAL_SECTION  m_csGettingFrame; 

	bool m_bHasWriteSPS;
	bool m_bHasWritePPS;
};

#endif
