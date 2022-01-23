#include "MediaElement.h"


string MediaElement::secondsToMinutes(unsigned int length) {
  string out = "";
  unsigned int tmp;
  char buf[256];

  tmp = length / 60;
  if (tmp < 10)
    out += "0";
  sprintf(buf, "%d", tmp);
  out += buf;

  out += ":";

  tmp = length % 60;
  if (tmp < 10)
    out += "0";
  sprintf(buf, "%d", tmp);
  out += buf;

  return out;
}

string MediaElement::secondsToHours(unsigned int length) {
  string out = "";
  unsigned int tmp;
  char buf[256];

  tmp = length / 3600;
  if (tmp < 10)
    out += "0";
  sprintf(buf, "%d", tmp);
  out += buf;

  out += ":";

  tmp = (length / 60) % 60;
  if (tmp < 10)
    out += "0";
  sprintf(buf, "%d", tmp);
  out += buf;

  out += ":";

  tmp = length % 60;
  if (tmp < 10)
    out += "0";
  sprintf(buf, "%d", tmp);
  out += buf;

  return out;
}