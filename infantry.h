#ifndef INFANTRY_H
#define INFANTRY_H


class Infantry
{
    /*
    enum ETeam
    {
      T_RED,
      T_BLUE,
    };

    enum EDirection
    {
      DIR_INVALID,

      DIR_LEFT,
      DIR_RIGHT,
      DIR_UP,
      DIR_DOWN,
    };

    inline EDirection GetDirectionFromOffset(const Vector2i &vOffset)
    {
      int x = vOffset(1);
      int y = vOffset(2);

      EDirection dir = DIR_INVALID;
      if(x != 0) {
        dir = (x > 0 ? DIR_RIGHT : DIR_LEFT);
      } else if(y != 0) {
        dir = (y > 0 ? DIR_DOWN : DIR_UP);
      }

      return dir;
    }

    inline ETeam GetTeamName(ETeam et)
    {
      switch(et) {
      case T_RED:   return "Red";
      case T_BLUE:   return "Blue";
      }
      */

public:
    Infantry();
};

#endif // INFANTRY_H
