#ifndef _SIGSLOT_h_
#define _SIGSLOT_h_

// sigslot.h - autor Kluev Alexander <kluev@pragmaworks.com>

template <class Arg>
class signal;

class slot {
        friend class signal_base;

        slot                            *_prev;
        slot                            *_next;

        struct Thunk {};
        typedef void (Thunk::*Func)();

        Thunk   *_trg;
        Func    _mfn;

public:

        slot() : _trg(0), _mfn(0), _prev(0), _next(0) {}
        ~slot() {
                clear();
        }

public:

        void clear() {
                if ( _next )
                        _next->_prev = _prev;
                if ( _prev )
                        _prev->_next = _next;
                _prev = _next = 0;
        }

        template <class Owner, class Arg>
        void init( signal<Arg> &sig, void (Owner::*mpfn)(Arg), Owner *This ) {
                clear();
                _trg = (Thunk*)This;
                _mfn = (Func)mpfn;
                sig._add( *this );
        }

        template <class Owner>
        void init( signal<void> &sig, void (Owner::*mpfn)(), Owner *This ) {
                clear();
                _trg = (Thunk*)This;
                _mfn = (Func)mpfn;
                sig._add( *this );
        }

private:


        template <class Arg>
        void _call( Arg a ) {
                typedef void (Thunk::*XFunc)(Arg);
                XFunc f = (XFunc)_mfn;
                (_trg->*f)(a);
        }

        void _call() {
                (_trg->*_mfn)();
        }
};

class signal_base {
protected:
        friend class slot;

        slot    _head;

        void _add( slot &s ) {
                s._prev = &_head;
                s._next = _head._next;

                if ( _head._next )
                        _head._next->_prev = &s;
                _head._next = &s;
        }

        template <class Arg>
        void _raise( Arg a ) {
                slot *p = _head._next;
                while ( p ) {
                        p->_call( a );
                        p = p->_next;
                }
        }

        void _raise() {
                slot *p = _head._next;
                while ( p ) {
                        p->_call();
                        p = p->_next;
                }
        }

public:

        ~signal_base() { clear(); }

public:

        void clear() {
                while ( _head._next )
                        _head._next->clear();
        }
};


template <class Arg>
class signal : public signal_base {
public:
        void raise( Arg );
};

typedef void VOID;

template <>
void signal<VOID>::raise() {
        signal_base::_raise();
}

template <class Arg>
void signal<Arg>::raise( Arg a ) {
        signal_base::_raise( a );
}

#endif // _SIGSLOT_h_
