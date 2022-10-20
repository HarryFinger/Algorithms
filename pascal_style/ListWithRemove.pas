program asd;
type
    itemptr = ^item;
    item = record
        data: integer;
        next: itemptr;
    end;

var
    val: integer;
    first, last, tmp: ^item;
    pp: ^itemptr;
    i: integer;


begin
    first := nil;
    while not SeekEof do
    begin
        read(val);
        if first = nil then
        begin
            new(first);
            last := first
        end
        else
        begin
            new(last^.next);
            last := last^.next
        end;
        last^.next := nil;
        last^.data := val
    end;

    // reducing negative item
    pp := @first;
    while pp^ <> nil do
    begin
        if pp^^.data < 0 then
        begin
            tmp := pp^;
            pp^ := pp^^.next;
            dispose(tmp)
        end
        else
            pp := @(pp^^.next)
    end;
    
    pp := @first;


    for i:=1 to 1 do
    begin
        pp := @(pp^^.next)
    end;
    
    new(tmp);
    tmp^.next := pp^;
    tmp^.data := 1111;
    pp^ := tmp;
    
    tmp := first;
    while tmp <> nil do
    begin
        writeln(tmp^.data);
        tmp := tmp^.next
    end

    
end.