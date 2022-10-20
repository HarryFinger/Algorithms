program Hello;
uses crt;
const
    Message = 'Hello, world!';
    DelayDuration = 7000;
var
    x,y: integer;
begin
    clrscr;
    x := (ScreenWidth - length(Message)) div 2;
    y := ScreenHeight div 2;
    GotoXY(x,y);
    write(Message);
    GotoXY(5,5);
    delay(DelayDuration);
    clrscr
end.