program Queue;

type 
    itemPtr = ^item;
    item = record
        data: integer;
        next: itemPtr;
    end;

type
    QueueOnList = record
        first, last: itemPtr;
        end;
        

procedure QOLInit(var que: QueueOnList);
begin
    que.first := nil;
    que.last := nil;
end;

procedure QOLPut(var que: QueueOnList; n: integer);
begin
    if que.first = nil then
    begin
        new(que.first);
        que.last := que.first
    end
    else
    begin
        new(que.last^.next);
        que.last := que.last^.next
    end;
    que.last^.data := n;
    que.last^.next := nil
end;

procedure QOLGet(var que: QueueOnList; var n: integer);
var
    tmp: itemPtr;
begin
    {n := que.first^.data;
    tmp := que.first;
    que.first := que.first^.next;
    if que.first = nil then
        que.last := nil;
    dispose(tmp)}
    if que.first = que.last then
    begin
        n := que.first^.data;
        dispose(que.first);
        que.first := nil
    end
    else
    begin
        n := que.first^.data;
        tmp := que.first;
        que.first := que.first^.next;
        dispose(tmp)
    end
end;

function QOLisEmpty(var que: QueueOnList): boolean;
begin
    QOLisEmpty := que.first = nil
end;

var
    c: integer;
    q: QueueOnList;

begin
    QOLInit(q);
    while not SeekEof do
    begin
        read(c);
        QOLPut(q, c);
    end;
    while not QOLisEmpty(q) do
    begin
        QOLGet(q, c);
        writeln(c);
    end
end.