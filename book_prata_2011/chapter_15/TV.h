#pragma once


class Tv
{
	friend class Remote;

public:
	enum {Off, On};
	enum {MinVal,MaxVal = 20};
	enum {Antenna, Cable};
	enum {TV, DVD};

	Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
	void onoff() {state = (state == On)? Off : On;}
	bool ison() const {return state == On;}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() {mode = (mode == Antenna)? Cable : Antenna;}
	void set_input() {input = (input == TV)? DVD : TV;}
	void settings() const; // display all settings
	void SetRemoteMode(Remote & r);

private:
	int state; // on or off
	int volume; // assumed to be digitized
	int maxchannel; // maximum number of channels
	int channel; // current channel setting
	int mode; // broadcast or cable
	int input; // TV or DVD
};


class Remote
{
	friend class Tv;

public:
	enum eState_t { NORMAL, INTERACTIVE };

private:
	eState_t RemoteMode_; // normal or interactive mode
	int mode_; // controls TV or DVD

public:
	Remote(eState_t rem_mode = NORMAL, int m = Tv::TV) : RemoteMode_(rem_mode), mode_(m) {}
	bool volup(Tv & t) { return t.volup();}
	bool voldown(Tv & t) { return t.voldown();}
	void onoff(Tv & t) { t.onoff(); }
	void chanup(Tv & t) {t.chanup();}
	void chandown(Tv & t) {t.chandown();}
	void set_chan(Tv & t, int c) {t.channel = c;}
	void set_mode(Tv & t) {t.set_mode();}
	void set_input(Tv & t) {t.set_input();}
	void RemoteState() const;
};