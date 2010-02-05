/******************************************************************************
/ TrackSends.h
/
/ Copyright (c) 2010 Tim Payne (SWS)
/ http://www.standingwaterstudios.com/reaper
/
/ Permission is hereby granted, free of charge, to any person obtaining a copy
/ of this software and associated documentation files (the "Software"), to deal
/ in the Software without restriction, including without limitation the rights to
/ use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
/ of the Software, and to permit persons to whom the Software is furnished to
/ do so, subject to the following conditions:
/ 
/ The above copyright notice and this permission notice shall be included in all
/ copies or substantial portions of the Software.
/ 
/ THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
/ EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
/ OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
/ NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
/ HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
/ WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
/ FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
/ OTHER DEALINGS IN THE SOFTWARE.
/
******************************************************************************/


#pragma once

class TrackSendFix
{
public:
	TrackSendFix(const GUID* oldGuid, const GUID* newGuid):m_oldGuid(*oldGuid),m_newGuid(*newGuid) { }
	GUID m_oldGuid;
	GUID m_newGuid;
};

class TrackSend
{
public:
	TrackSend(GUID* guid, const char* str);
	TrackSend(GUID* guid, int iMode, double dVol, double dPan, int iMute, int iMono, int iPhase, int iSrc, int iDest, int iMidi, int iAuto);
	TrackSend(const char* str);
	TrackSend(TrackSend& ts);
	WDL_String* AuxRecvString(MediaTrack* srcTr, WDL_String* str);
	void GetChunk(WDL_String* chunk);
	const GUID* GetGuid() { return &m_destGuid; }
	void SetGuid(const GUID* guid) { m_destGuid = *guid; }

private:
	GUID m_destGuid;
	WDL_String m_str;
};

class TrackSends
{
public:
	TrackSends() { }
	TrackSends(TrackSends& ts);
	~TrackSends();
	void Build(MediaTrack* tr);
	void UpdateReaper(MediaTrack* tr, WDL_PtrList<TrackSendFix>* pFix);
	void GetChunk(WDL_String* chunk);

// TODO these should be private
	WDL_PtrList<WDL_String> m_hwSends;
	WDL_PtrList<TrackSend> m_sends;
};