///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2016 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: main.hpp
///
/// Author: $author$
///   Date: 7/26/2016
///////////////////////////////////////////////////////////////////////
#ifndef _XENE_CONSOLE_MAIN_HPP
#define _XENE_CONSOLE_MAIN_HPP

#include "xene/console/main_opt.hpp"
#include "xene/io/logger.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPT "logging"
#define XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT 0
#define XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG XENE_MAIN_LOGGING_OPTARG
#define XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE XENE_MAIN_LOGGING_OPTUSE
#define XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S "l:"
#define XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C 'l'
#define XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
   {XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPT, \
    XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_REQUIRED, \
    XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG_RESULT, \
    XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C}, \

#define XENE_CONSOLE_MAIN_HELP_OPT "help"
#define XENE_CONSOLE_MAIN_HELP_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XENE_CONSOLE_MAIN_HELP_OPTARG_RESULT 0
#define XENE_CONSOLE_MAIN_HELP_OPTARG XENE_MAIN_HELP_OPTARG
#define XENE_CONSOLE_MAIN_HELP_OPTUSE XENE_MAIN_HELP_OPTUSE
#define XENE_CONSOLE_MAIN_HELP_OPTVAL_S "?"
#define XENE_CONSOLE_MAIN_HELP_OPTVAL_C '?'
#define XENE_CONSOLE_MAIN_HELP_OPTION \
   {XENE_CONSOLE_MAIN_HELP_OPT, \
    XENE_CONSOLE_MAIN_HELP_OPTARG_REQUIRED, \
    XENE_CONSOLE_MAIN_HELP_OPTARG_RESULT, \
    XENE_CONSOLE_MAIN_HELP_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XENE_CONSOLE_MAIN_OPTIONS_CHARS \
    XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_S \
    XENE_CONSOLE_MAIN_HELP_OPTVAL_S \

#define XENE_CONSOLE_MAIN_OPTIONS_OPTIONS \
    XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTION \
    XENE_CONSOLE_MAIN_HELP_OPTION \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace xene {
namespace console {

typedef xos::base::getopt::main_implement main_implements;
typedef xos::base::getopt::main main_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template
<class TImplements = main_implements, class TExtends = main_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    maint() {
    }
    virtual ~maint() {
    }

protected:
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_logging_levels_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = this->on_logging_option
        (XENE_MAIN_LOGGING_OPTVAL_C,
         optarg, optname, optind, argc, argv, env);
        return err;
    }
    ///////////////////////////////////////////////////////////////////////
    virtual int on_help_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = this->usage(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int on_option
    (int optval, const char* optarg,
     const char* optname, int optind,
     int argc, char**argv, char**env) {
        int err = 0;
        switch(optval) {
        case XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            err = on_logging_levels_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XENE_CONSOLE_MAIN_HELP_OPTVAL_C:
            err = on_help_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = Extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* option_usage
    (const char*& optarg, const struct option* longopt) {
        const char* chars = "";
        switch(longopt->val) {
        case XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTVAL_C:
            optarg = XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTARG;
            chars = XENE_CONSOLE_MAIN_LOGGING_LEVELS_OPTUSE;
            break;
        case XENE_CONSOLE_MAIN_HELP_OPTVAL_C:
            optarg = XENE_CONSOLE_MAIN_HELP_OPTARG;
            chars = XENE_CONSOLE_MAIN_HELP_OPTUSE;
            break;
        default:
            chars = Extends::option_usage(optarg, longopt);
        }
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual const char* options(const struct option*& longopts) {
        int err = 0;
        static const char* chars = XENE_CONSOLE_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XENE_CONSOLE_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
public:
    class _EXPORT_CLASS in_reader;
    class _EXPORT_CLASS out_writer;
    class _EXPORT_CLASS err_writer;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
protected:
};

typedef xos::io::main::in::readert
<char, char, int, 0, main_extends, io::char_reader> main_in_reader;
///////////////////////////////////////////////////////////////////////
///  Class: maint<TImplements, TExtends>::in_reader
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>
class _EXPORT_CLASS maint
<TImplements, TExtends>::in_reader: public main_in_reader {
public:
    typedef main_in_reader Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    in_reader(TExtends& to): Extends(to) {}
    in_reader(const in_reader& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef xos::io::main::out::writert
<char, char, int, 0, main_extends, io::char_writer> main_out_writer;
///////////////////////////////////////////////////////////////////////
///  Class: maint<TImplements, TExtends>::out_writer
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>
class _EXPORT_CLASS maint
<TImplements, TExtends>::out_writer: public main_out_writer {
public:
    typedef main_out_writer Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    out_writer(TExtends& to): Extends(to) {}
    out_writer(const out_writer& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef xos::io::main::err::writert
<char, char, int, 0, main_extends, io::char_writer> main_err_writer;
///////////////////////////////////////////////////////////////////////
///  Class: maint<TImplements, TExtends>::err_writer
///////////////////////////////////////////////////////////////////////
template <class TImplements, class TExtends>
class _EXPORT_CLASS maint
<TImplements, TExtends>::err_writer: public main_err_writer {
public:
    typedef main_err_writer Extends;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    err_writer(TExtends& to): Extends(to) {}
    err_writer(const err_writer& copy): Extends(copy) {}
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

typedef maint<> main;

} // namespace console
} // namespace xene 

#endif // _XENE_CONSOLE_MAIN_HPP 
