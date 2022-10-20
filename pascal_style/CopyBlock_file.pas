program asd;

const
    BufSize = 4096;
var
    src, dest: file;
    buffer: array [1..BufSize] of byte;
    ReadRes, WriteRes: longint;
begin
    {$I-}
    if ParamCount < 2 then
        begin
            writeln (ErrOutput, 'Expected: 2 params');
            halt(1)
        end;
    assign(src, ParamStr(1));
    assign(dest, ParamStr(2));
    filemode := 0;
    reset(src, 1);
    if IOResult <>0 then
    begin
        writeln(ErrOutput, 'Can''t open ', Paramstr(1));
        halt(1)
    end;
    filemode := 1;
    rewrite(dest,1);
    if IOResult <>0 then
    begin
        writeln(ErrOutput, 'Can''t open ', Paramstr(2));
        halt(1)
    end;
    while true do
    begin
        BlockRead(src, buffer, BufSize, ReadRes);
        if ReadRes = 0 then
            break;
        BlockWrite(dest, buffer, ReadRes, WriteRes);
        if WriteRes <> ReadRes then
        begin
            writeln(ErrOutput, 'Error writing the file');
            break
        end
    end;
    close(src);
    close(dest)
end.