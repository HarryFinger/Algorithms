program py;

const
    MaxSize =67;
    MaxGroop =100;
type
    CounterArray = array [1..MaxSize] of integer;
var
    arrayC: CounterArray;
    n,c,i: integer;
begin
    for i:=1 to MaxSize do
    arrayC[i] := 0;
    while not eof do
    begin
        readln(c);
        n := c div MaxGroop;
        if (n < 1) and (n > MaxSize) then
        halt(1);
        arrayC[n] := arrayC[n]+1;
    end;
    for i:=1 to MaxSize do
    begin
        if (arrayC[i] <> 0 ) then
        writeln('School №', i, ' have ', arrayC[i], ' members.')
    end;
end.