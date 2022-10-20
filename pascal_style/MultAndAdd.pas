program asd;

var 
    sum, mul, n: real;
    f:text;
begin
    {$I-}
    if ParamCount < 1 then
    begin
        writeln('Enter file name as arg');
        halt(1)
    end;
    assign(f, ParamStr(1));
    reset(f);
    if IOResult <> 0 then
    begin
        writeln('File ', ParamStr(1),' not open');
        halt(1)
    end;
    sum := 0;
    while not SeekEof(f) do
    begin
        mul :=1;
        while not SeekEoln(f) do
        begin
            read(f,n);
            mul := mul * n
        end;
        readln(f);
        sum := sum + mul;
    end;
    close(f);
    writeln (sum:7:5)
end.
