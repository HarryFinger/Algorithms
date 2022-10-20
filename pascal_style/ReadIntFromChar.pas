program py;

procedure ReadInt(var success: boolean; var result: longint);
var
    c : char;
    pos,res : longint;
begin
    pos := 0;
    res := 0;
    repeat
        read(c);
        pos := pos + 1;
    until (c <> ' ') and (c <> #10);
    while (c <> ' ') and (c <> #10) do
    begin 
        if (c < '0') or (c > '9') then
        begin
            writeln('ERROR!!!');
            readln;
            success := false;
            exit
        end;
        res := res*10 + ord(c) - ord('0');
        read(c);
        pos := pos +1;
    end;
    result := res;
    success := true 
end;

var
    x : longint;
    ok : boolean = false;    
begin


        ReadInt(ok,x);
    
    writeln(x)
end.