program listR;

type
    plist = ^item;
    item = record
        data: integer;
        next: plist;
    end;

var
    i: integer;
    myList, tmp: plist;

procedure initList(var p: plist; n: integer);
begin
    p := nil;
    for i := 1 to n do
    begin
        new(tmp);
        tmp^.data := i;
        tmp^.next := p;
        p := tmp
    end
end;

procedure deleteHalfRec(var p: plist);
begin
    if p = nil then exit;
    deleteHalfRec(p^.next);
    dispose(p)
end;

procedure printMyList(var p: plist);
begin
    tmp := p;
    while tmp <> nil do
    begin
        writeln(tmp^.data);
        tmp := tmp^.next
    end
end;

function sumRec(var p: plist): integer;
begin
    if p = nil then sumRec := 0
    else sumRec := p^.data + sumRec(p^.next)
end;

begin
    initList(myList, 3);
    writeln(sumRec(myList));
    //printMyList(myList)
end.