program asd;
uses crt;
var
    Message: string = '*****';

procedure GetKey(var code:integer);
var
    c:char;
begin
    c:=ReadKey;
    if c = #0 then
    begin
        c:=ReadKey;
        code := -ord(c)
    end
    else
    begin
        code := ord(c);
    end
end;

procedure ShowMessage(x,y: integer; msg: string);
begin
    GotoXY(x,y);
    write(msg);
    GotoXY(1,1)
end;

procedure HideMessage(x,y: integer; msg: string);
var
    len, i: integer;
begin
    len := length(msg);
    GotoXY(x,y);
    for i := 0 to len do
        write(' ');
    GotoXY(1,1)
end;

procedure MoveMessage(var x,y: integer; msg: string; dx,dy: integer);
begin
    HideMessage(x,y, msg);
    x := x+dx;
    y := y+dy;
    ShowMessage(x,y,msg)
end;

var CurX,CurY: integer;
    c: integer;
begin
    clrscr;
    CurX := (ScreenWidth - length(Message)) div 2;
    CurY := (ScreenHeight div 2);
    ShowMessage(CurX,CurY, Message);
    while true do
    begin
        GetKey(c);
        if ((c > 0) and (c <> ord('=')) and (c <> ord('-'))) then
            break;
        case c of
            -75:
                MoveMessage(CurX,CurY,Message,-1,0);
            -77:
                MoveMessage(CurX,CurY,Message,1,0);
            -72:
                MoveMessage(CurX,CurY,Message,0,-1);
            -80:
                MoveMessage(CurX,CurY,Message,0,1);
            ord('='):
            begin
                Message := Message +'*';
                MoveMessage(CurX,CurY,Message,0,0)
            end;
            ord('-'):
            begin
                delete(Message,length(Message),1);
                MoveMessage(CurX,CurY,Message,0,0)
            end
        end
    end;
    clrscr
end.