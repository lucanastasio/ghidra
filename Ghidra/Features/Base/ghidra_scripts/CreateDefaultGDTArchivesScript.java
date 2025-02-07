/* ###
 * IP: GHIDRA
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//
// Parses default header file gdt archives
//
// To replace existing header files and have the data type ID's synchronized
//
// Must run SynchronizeGDTCategoryPaths.java script with old and replacement GDT
//  archive to synchronize upper/lower case paths
///   (only on windows archives)
//
// Then Run DataTypeArchiveTransformer in eclipse to synchronize old data types ID's
//
//@category Data Types

import java.io.File;
import java.io.IOException;

import ghidra.app.script.GhidraScript;
import ghidra.app.util.cparser.C.CParserUtils;
import ghidra.app.util.cparser.C.ParseException;
import ghidra.program.model.data.DataTypeManager;
import ghidra.program.model.data.FileDataTypeManager;
import ghidra.util.Msg;
import ghidra.util.task.TaskMonitor;

public class CreateDefaultGDTArchivesScript extends GhidraScript {

	private File outputDirectory;
	
	private static String headerFilePath = "/data/HeaderFiles";

	@Override
	protected void run() throws Exception {
		outputDirectory = askDirectory("Select Directory for GDT files", "Select GDT Output Dir");

		parseGDT_CLIB32();
		parseGDT_CLIB64();
		
		parseGDT_VS12_32();
		parseGDT_VS12_64();

	}
	
	private void parseHeaderFilesToGDT(File outputDir, String gdtName, String languageID, String compiler, String[] filenames, String[] args)
			throws ParseException, ghidra.app.util.cparser.CPP.ParseException, IOException {
		DataTypeManager openTypes[] = null;
		
		parseHeaderFilesToGDT(openTypes, outputDir, gdtName, languageID, compiler, filenames, args);
	}

	private void parseHeaderFilesToGDT(DataTypeManager openTypes[], File outputDir, String gdtName, String languageID, String compiler, String[] filenames, String[] args)
			throws ParseException, ghidra.app.util.cparser.CPP.ParseException, IOException {
		
		String dataTypeFile = outputDir + File.separator + gdtName + ".gdt";
		
		File f = getArchiveFile(dataTypeFile);
		
        FileDataTypeManager dtMgr = FileDataTypeManager.createFileArchive(f);
        
		String messages = CParserUtils.parseHeaderFiles(openTypes, filenames, args, dtMgr, languageID, compiler, null, monitor);
		
		Msg.info(this, messages);

		dtMgr.save();
		dtMgr.close();
	}

	/**
	 * Turn string into a file, delete old archive if it exists
	 * 
	 * @param dataTypeFile
	 * 
	 * @return file
	 */
	private File getArchiveFile(String dataTypeFile) {
		File f = new File(dataTypeFile);
		if (f.exists()) {
			f.delete();
		}
		String lockFile = dataTypeFile + ".ulock";
		File lf = new File(lockFile);
		if (lf.exists()) {
			lf.delete();
		}
		return f;
	}
	
	public void parseGDT_VS12_32() throws Exception {
		
		String filenames[] = {
				"sdkddkver.h",
				"sal.h",
				"assert.h",
				"conio.h",
				"crtdefs.h",
				"crtdbg.h",
				"crtwrn.h",
				"ctype.h",
				"basetsd.h",
				"WinDef.h",
				"WinNT.h",
				"delayimp.h",
				"direct.h",
				"dos.h",
				"errno.h",
				"excpt.h",
				"fcntl.h",
				"float.h",
				"fpieee.h",
				"io.h",
				"iso646.h",
				"limits.h",
				"locale.h",
				"malloc.h",
				"math.h",
				"mbctype.h",
				"mbstring.h",
				"memory.h",
				"minmax.h",
				"new.h",
				"omp.h",
				"pgobootrun.h",
				"process.h",
				"rtcapi.h",
				"search.h",
				"setjmp.h",
				"setjmpex.h",
				"share.h",
				"signal.h",
				"srv.h",
				"stdarg.h",
				"stddef.h",
				"stdexcpt.h",
				"stdio.h",
				"stdlib.h",
				"string.h",
				"tchar.h",
				"time.h",
				"use_ansi.h",
				"vadefs.h",
				"varargs.h",
				"wchar.h",
				"wctype.h",
				"xlocinfo.h",
				"xmath.h",
				"ymath.h",
				"yvals.h",
				"CommDlg.h",
				"WinUser.h",
				"WinNls.h",
				"internal.h",
				"strsafe.h",
				"align.h",
				"awint.h",
				"crtversion.h",
				"cruntime.h",
				"ctime.h",
				"cvt.h",
				"dbgint.h",
				"ehdata.h",
				"emmintrin.h",
				"errmsg.h",
				"fenv.h",
				"file2.h",
				"fltintrn.h",
				"immintrin.h",
				"internal_securecrt.h",
				"inttypes.h",
				"isa_availability.h",
				"mbdata.h",
				"msdos.h",
				"mtdll.h",
				"nlsdownlevel.h",
				"nlsint.h",
				"nmmintrin.h",
				"oscalls.h",
				"pmmintrin.h",
				"rtcsup.h",
				"rterr.h",
				"sect_attribs.h",
				"setlocal.h",
				"smmintrin.h",
				"stdbool.h",
				"stdint.h",
				"syserr.h",
				"targetver.h",
				"tmmintrin.h",
				"winheap.h",
				"wmmintrin.h",
				"wrapwin.h",
				"xkeycheck.h",
				"xmmintrin.h",
				"xmtx.h",
				"xtgmath.h",
				"xxcctype.h",
				"xxdftype.h",
				"xxfftype.h",
				"xxlftype.h",
				"xxwctype.h",
				"xxxprec.h",
				"shlobj.h",
				"evntprov.h",
				"uiautomation.h",
				"aclapi.h",
				"appcompatapi.h",
				"capi.h",
				"clusapi.h",
				"cryptuiapi.h",
				"cscapi.h",
				"devpropdef.h",
				"dhcpsapi.h",
				"dwmapi.h",
				"ehstorapi.h",
				"functiondiscoveryapi.h",
				"ipexport.h",
				"icmpapi.h",
				"iepmapi.h",
				"imapi.h",
				"ksopmapi.h",
				"locationapi.h",
				"lpmapi.h",
				"mapi.h",
				"mbnapi.h",
				"mfapi.h",
				"mgmtapi.h",
				"mmdeviceapi.h",
				"mprapi.h",
				"msctfmonitorapi.h",
				"ndfapi.h",
				"netioapi.h",
				"npapi.h",
				"nspapi.h",
				"ntdsapi.h",
				"ntmsapi.h",
				"ntsecapi.h",
				"patchapi.h",
				"portabledeviceapi.h",
				"portabledeviceconnectapi.h",
				"propapi.h",
				"psapi.h",
				"rdpencomapi.h",
				"resapi.h",
				"sapi.h",
				"searchapi.h",
				"sensapi.h",
				"sensorsapi.h",
				"setupapi.h",
				"shellapi.h",
				"shlwapi.h",
				"srrestoreptapi.h",
				"svrapi.h",
				"t2embapi.h",
				"tapi.h",
				"uiautomationcoreapi.h",
				"wcnapi.h",
				"wdsclientapi.h",
				"werapi.h",
				"windowssideshowapi.h",
				"wlanapi.h",
				"wpapi.h",
				"wpcapi.h",
				"wscapi.h",
				"wsdapi.h",
				"wspiapi.h",

				"rpcproxy.h",
		};
		
		String args[] = {
				"-I"+headerFilePath+"/VC/VS12/src",
				"-I"+headerFilePath+"/VC/VS12/include",
				"-I"+headerFilePath+"/VC/SDK/v7.1A/Include",
				"-D_M_IX86=300",
				"-D_MSC_VER=1200",
				"-D_INTEGRAL_MAX_BITS=32",
				"-DWINVER=0x0900",
				"-D_X86_",
				"-D_WIN32",
				"-DCRTDLL",
				"-D_USE_ATTRIBUTES_FOR_SAL",
				"-D_CRTBLD",
				"-D_OPENMP_NOFORCE_MANIFEST",
				"-DLPSKBINFO=LPARAM",
				"-DCONST=const",
				"-D_CRT_SECURE_NO_WARNINGS",
				"-D_CRT_NONSTDC_NO_DEPRECATE",
				"-D_CRT_NONSTDC_NO_WARNINGS",
				"-D_CRT_OBSOLETE_NO_DEPRECATE",
				"-D_ALLOW_KEYWORD_MACROS",
				"-D_ASSERT_OK",
				"-DSTRSAFE_NO_DEPRECATE",
				"-D__possibly_notnullterminated",
				"-Dtype_info=\"void *\"",
				"-D_ThrowInfo=ThrowInfo",
				"-v0",
				"-D__inner_checkReturn=",
		};
		
		parseHeaderFilesToGDT(outputDirectory, "windows_vs12_32_new", "x86:LE:32:default", "windows", filenames, args);
	}

	
	
	public void parseGDT_VS12_64() throws Exception {
		
		String filenames[] = {
				"sdkddkver.h",
				"sal.h",
				"assert.h",
				"conio.h",
				"crtdefs.h",
				"crtdbg.h",
				"crtwrn.h",
				"ctype.h",
				"basetsd.h",
				"WinDef.h",
				"WinNT.h",
				"delayimp.h",
				"direct.h",
				"dos.h",
				"errno.h",
				"excpt.h",
				"fcntl.h",
				"float.h",
				"fpieee.h",
				"io.h",
				"iso646.h",
				"limits.h",
				"locale.h",
				"malloc.h",
				"math.h",
				"mbctype.h",
				"mbstring.h",
				"memory.h",
				"minmax.h",
				"new.h",
				"omp.h",
				"pgobootrun.h",
				"process.h",
				"rtcapi.h",
				"search.h",
				"setjmp.h",
				"setjmpex.h",
				"share.h",
				"signal.h",
				"srv.h",
				"stdarg.h",
				"stddef.h",
				"stdexcpt.h",
				"stdio.h",
				"stdlib.h",
				"string.h",
				"tchar.h",
				"time.h",
				"use_ansi.h",
				"vadefs.h",
				"varargs.h",
				"wchar.h",
				"wctype.h",
				"xlocinfo.h",
				"xmath.h",
				"ymath.h",
				"yvals.h",
				"CommDlg.h",
				"WinUser.h",
				"WinNls.h",
				"internal.h",
				"strsafe.h",
				"align.h",
				"awint.h",
				"crtversion.h",
				"cruntime.h",
				"ctime.h",
				"cvt.h",
				"dbgint.h",
				"ehdata.h",
				"emmintrin.h",
				"errmsg.h",
				"fenv.h",
				"file2.h",
				"fltintrn.h",
				"immintrin.h",
				"internal_securecrt.h",
				"inttypes.h",
				"isa_availability.h",
				"mbdata.h",
				"msdos.h",
				"mtdll.h",
				"nlsdownlevel.h",
				"nlsint.h",
				"nmmintrin.h",
				"oscalls.h",
				"pmmintrin.h",
				"rtcsup.h",
				"rterr.h",
				"sect_attribs.h",
				"setlocal.h",
				"smmintrin.h",
				"stdbool.h",
				"stdint.h",
				"syserr.h",
				"targetver.h",
				"tmmintrin.h",
				"winheap.h",
				"wmmintrin.h",
				"wrapwin.h",
				"xkeycheck.h",
				"xmmintrin.h",
				"xmtx.h",
				"xtgmath.h",
				"xxcctype.h",
				"xxdftype.h",
				"xxfftype.h",
				"xxlftype.h",
				"xxwctype.h",
				"xxxprec.h",
				"shlobj.h",
				"evntprov.h",
				"uiautomation.h",
				"aclapi.h",
				"appcompatapi.h",
				"capi.h",
				"clusapi.h",
				"cryptuiapi.h",
				"cscapi.h",
				"devpropdef.h",
				"dhcpsapi.h",
				"dwmapi.h",
				"ehstorapi.h",
				"functiondiscoveryapi.h",
				"ipexport.h",
				"icmpapi.h",
				"iepmapi.h",
				"imapi.h",
				"ksopmapi.h",
				"locationapi.h",
				"lpmapi.h",
				"mapi.h",
				"mbnapi.h",
				"mfapi.h",
				"mgmtapi.h",
				"mmdeviceapi.h",
				"mprapi.h",
				"msctfmonitorapi.h",
				"ndfapi.h",
				"netioapi.h",
				"npapi.h",
				"nspapi.h",
				"ntdsapi.h",
				"ntmsapi.h",
				"ntsecapi.h",
				"patchapi.h",
				"portabledeviceapi.h",
				"portabledeviceconnectapi.h",
				"propapi.h",
				"psapi.h",
				"rdpencomapi.h",
				"resapi.h",
				"sapi.h",
				"searchapi.h",
				"sensapi.h",
				"sensorsapi.h",
				"setupapi.h",
				"shellapi.h",
				"shlwapi.h",
				"srrestoreptapi.h",
				"svrapi.h",
				"t2embapi.h",
				"tapi.h",
				"uiautomationcoreapi.h",
				"wcnapi.h",
				"wdsclientapi.h",
				"werapi.h",
				"windowssideshowapi.h",
				"wlanapi.h",
				"wpapi.h",
				"wpcapi.h",
				"wscapi.h",
				"wsdapi.h",
				"wspiapi.h",

				"rpcproxy.h",
		};
		
		String args[] = {
				"-I"+headerFilePath+"/VC/VS12/src",
				"-I"+headerFilePath+"/VC/VS12/include",
				"-I"+headerFilePath+"/VC/SDK/v7.1A/Include",
				"-D_MSC_VER=1200",
				"-D_INTEGRAL_MAX_BITS=64",
				"-DWINVER=0x0900",
				"-D_AMD64_",
				"-D_M_AMD64",
				"-D_M_X64",
				"-D_WIN64",
				"-D_WIN32",
				"-D_USE_ATTRIBUTES_FOR_SAL",
				"-D_CRTBLD",
				"-D_OPENMP_NOFORCE_MANIFEST",
				"-DLPSKBINFO=LPARAM",
				"-DCONST=const",
				"-D_CRT_SECURE_NO_WARNINGS",
				"-D_CRT_NONSTDC_NO_DEPRECATE",
				"-D_CRT_NONSTDC_NO_WARNINGS",
				"-D_CRT_OBSOLETE_NO_DEPRECATE",
				"-D_ALLOW_KEYWORD_MACROS",
				"-D_ASSERT_OK",
				"-DSTRSAFE_NO_DEPRECATE",
				"-D__possibly_notnullterminated",
				"-Dtype_info=\"void *\"",
				"-D_ThrowInfo=ThrowInfo",
				"-D__unaligned=",
				"-v0",
				"-D__inner_checkReturn=",
		};
		
		parseHeaderFilesToGDT(outputDirectory, "windows_vs12_64_new", "x86:LE:64:default", "windows", filenames, args);
	}
	
	
	public void parseGDT_CLIB64() throws Exception {
		
		String filenames[] = {
				"sys/types.h",
				"types.h",
				"stddef.h",
				"stddef.h",
				"openssl/opensslconf-x86_64.h",
				"openssl/bn.h",
				"openssl/ssl.h",
				"openssl/asn1_mac.h",
				"openssl/asn1t.h",
				"openssl/blowfish.h",
				"openssl/camellia.h",
				"openssl/cast.h",
				"openssl/cmac.h",
				"openssl/cms.h",
				"openssl/conf_api.h",
				"openssl/des.h",
				"openssl/dso.h",
				"openssl/engine.h",
				"openssl/fips_rand.h",
				"openssl/idea.h",
				"openssl/krb5_asn.h",
				"openssl/md2.h",
				"openssl/md4.h",
				"openssl/md5.h",
				"openssl/ocsp.h",
				"openssl/pkcs12.h",
				"openssl/rc2.h",
				"openssl/rc4.h",
				"openssl/ripemd.h",
				"openssl/seed.h",
				"openssl/ssl3.h",
				"openssl/txt_db.h",
				"openssl/whrlpool.h",
				"aio.h",
				"arpa/inet.h",
				"cpio.h",
				"dirent.h",
				"fcntl.h",
				"fmtmsg.h",
				"fnmatch.h",
				"ftw.h",
				"glob.h",
				"grp.h",
				"iconv.h",
				"langinfo.h",
				"libgen.h",
				"monetary.h",
				"mqueue.h",
				"ndbm.h",
				"net/if.h",
				"netdb.h",
				"netinet/in.h",
				"netinet/tcp.h",
				"nl_types.h",
				"poll.h",
				"pthread.h",
				"pwd.h",
				"regex.h",
				"sched.h",
				"search.h",
				"semaphore.h",
				"spawn.h",
				"strings.h",
				"stropts.h",
				"sys/ipc.h",
				"sys/mman.h",
				"sys/msg.h",
				"sys/resource.h",
				"sys/select.h",
				"sys/sem.h",
				"sys/shm.h",
				"sys/socket.h",
				"sys/stat.h",
				"sys/statvfs.h",
				"sys/time.h",
				"sys/times.h",
				"sys/types.h",
				"sys/uio.h",
				"sys/un.h",
				"sys/utsname.h",
				"sys/wait.h",
				"syslog.h",
				"tar.h",
				"termios.h",
				"trace.h",
				"ulimit.h",
				"unistd.h",
				"utime.h",
				"utmpx.h",
				"wordexp.h",
				"assert.h",
				"complex.h",
				"ctype.h",
				"fenv.h",
				"float.h",
				"inttypes.h",
				"iso646.h",
				"limits.h",
				"locale.h",
				"math.h",
				"setjmp.h",
				"signal.h",
				"stdarg.h",
				"stdbool.h",
				"stddef.h",
				"stdint.h",
				"stdio.h",
				"stdlib.h",
				"string.h",
				"tgmath.h",
				"time.h",
				"wchar.h",
				"wctype.h",
				"sys/acct.h",
				"sys/debugreg.h",
				"sys/epoll.h",
				"sys/eventfd.h",
				"sys/fcntl.h",
				"sys/fsuid.h",
				"sys/gmon.h",
				"sys/gmon_out.h",
				"sys/inotify.h",
				"sys/io.h",
				"sys/kd.h",
				"sys/kdaemon.h",
				"sys/klog.h",
				"sys/mount.h",
				"sys/mtio.h",
				"sys/pci.h",
				"sys/perm.h",
				"sys/personality.h",
				"sys/prctl.h",
				"sys/profil.h",
				"sys/ptrace.h",
				"sys/quota.h",
				"sys/raw.h",
				"sys/reboot.h",
				"sys/reg.h",
				"sys/sem.h",
				"sys/sendfile.h",
				"sys/signal.h",
				"sys/signalfd.h",
				"sys/socketvar.h",
				"sys/soundcard.h",
				"sys/statvfs.h",
				"sys/swap.h",
				"sys/sysctl.h",
				"sys/sysinfo.h",
				"sys/termios.h",
				"sys/timerfd.h",
				"sys/ttychars.h",
				"sys/ultrasound.h",
				"sys/unistd.h",
				"sys/ustat.h",
				"sys/vfs.h",
				"sys/vlimit.h",
				"sys/vt.h",
				"sys/vtimes.h",
				"sys/xattr.h",
				"errno.h",
				"mathcalls.h",
				"net/ethernet.h",
				"net/if_arp.h",
				"net/if_ppp.h",
				"net/if_slip.h",
				"net/ppp_defs.h",
				"net/if.h",
				"net/if_packet.h",
				"net/if_shaper.h",
				"net/ppp-comp.h",
				"net/route.h",
				"netinet/ether.h",
				"netinet/if_fddi.h",
				"netinet/in.h	",
				"netinet/ip6.h",
				"netinet/udp.h",
				"netinet/icmp6.h",
				"netinet/if_tr.h",
				"netinet/in_systm.h",
				"netinet/ip_icmp.h",
				"netinet/if_ether.h",
				"netinet/igmp.h",
				"netinet/ip.h",
				"netinet/tcp.h",
				"rpc/types.h",
				"rpc/auth.h",
				"rpc/des_crypt.h",
				"rpc/pmap_prot.h",
				"rpc/rpc_msg.h",
				"rpc/xdr.h",
				"rpc/auth_des.h",
				"rpc/key_prot.h",
				"rpc/pmap_rmt.h",
				"rpc/svc.h",
				"rpc/auth_unix.h",
				"rpc/netdb.h",
				"rpc/rpc.h",
				"rpc/svc_auth.h",
				"rpc/clnt.h",
				"rpc/pmap_clnt.h",
				"rpc/rpc_des.h",
				"rpcsvc/bootparam.h",
				"rpcsvc/nis_callback.h",
				"rpcsvc/yp_prot.h",
				"rpcsvc/rstat.h",
				"rpcsvc/rusers.h",
				"rpcsvc/spray.h",
				"rpcsvc/ypupd.h",
				"rpcsvc/mount.h",
				"rpcsvc/nis.h",
				"protocols/routed.h",
				"protocols/rwhod.h",
				"protocols/talkd.h",
				"protocols/timed.h",
				"arpa/ftp.h",
				"arpa/inet.h",
				"arpa/nameser.h",
				"arpa/nameser_compat.h",
				"arpa/telnet.h",
				"arpa/tftp.h",
		};
		
		String args[] = {
				"-I"+headerFilePath+"/linux/include",
				"-I"+headerFilePath+"/linux/include/sys",
				"-I"+headerFilePath+"/linux/gcc/include",
				"-I"+headerFilePath+"/linux/x86_64-redhat-linux5E/include",
				"-I"+headerFilePath+"/linux/x86_64-redhat-linux5E/include/sys",
				"-D_X86_",
				"-D__STDC__",
				"-D_GNU_SOURCE",
				"-D__WORDSIZE=64",
				"-D__builtin_va_list=void *",
				"-D__DO_NOT_DEFINE_COMPILE",
				"-D_Complex",
				"-D__NO_STRING_INLINES",
				"-D__signed__",
				"-D__extension__=",
				"-D__GLIBC_HAVE_LONG_LONG=1",
				"-D__need_sigset_t",
				"-Daligned_u64=uint64_t",
		};
		
		parseHeaderFilesToGDT(outputDirectory, "generic_clib_64_new", "x86:LE:64:default", "gcc", filenames, args);
	}
	
	
	public void parseGDT_CLIB32() throws Exception {
		
		String filenames[] = {
				"sys/types.h",
				"types.h",
				"stddef.h",
				"stddef.h",
				"openssl/opensslconf-x86_64.h",
				"openssl/des.h",
				"openssl/bn.h",
				"openssl/ssl.h",
				"openssl/asn1_mac.h",
				"openssl/asn1t.h",
				"openssl/blowfish.h",
				"openssl/camellia.h",
				"openssl/cast.h",
				"openssl/cmac.h",
				"openssl/cms.h",
				"openssl/conf_api.h",
				"openssl/dso.h",
				"openssl/engine.h",
				"openssl/fips_rand.h",
				"openssl/idea.h",
				"openssl/krb5_asn.h",
				"openssl/md2.h",
				"openssl/md4.h",
				"openssl/md5.h",
				"openssl/ocsp.h",
				"openssl/pkcs12.h",
				"openssl/rc2.h",
				"openssl/rc4.h",
				"openssl/ripemd.h",
				"openssl/seed.h",
				"openssl/ssl3.h",
				"openssl/txt_db.h",
				"openssl/whrlpool.h",
				"aio.h",
				"arpa/inet.h",
				"cpio.h",
				"dirent.h",
				"fcntl.h",
				"fmtmsg.h",
				"fnmatch.h",
				"ftw.h",
				"glob.h",
				"grp.h",
				"iconv.h",
				"langinfo.h",
				"libgen.h",
				"monetary.h",
				"mqueue.h",
				"ndbm.h",
				"net/if.h",
				"netdb.h",
				"netinet/in.h",
				"netinet/tcp.h",
				"nl_types.h",
				"poll.h",
				"pthread.h",
				"pwd.h",
				"regex.h",
				"sched.h",
				"search.h",
				"semaphore.h",
				"spawn.h",
				"strings.h",
				"stropts.h",
				"sys/ipc.h",
				"sys/mman.h",
				"sys/msg.h",
				"sys/resource.h",
				"sys/select.h",
				"sys/sem.h",
				"sys/shm.h",
				"sys/socket.h",
				"sys/stat.h",
				"sys/statvfs.h",
				"sys/time.h",
				"sys/times.h",
				"sys/types.h",
				"sys/uio.h",
				"sys/un.h",
				"sys/utsname.h",
				"sys/wait.h",
				"syslog.h",
				"tar.h",
				"termios.h",
				"trace.h",
				"ulimit.h",
				"unistd.h",
				"utime.h",
				"utmpx.h",
				"wordexp.h",
				"assert.h",
				"complex.h",
				"ctype.h",
				"fenv.h",
				"float.h",
				"inttypes.h",
				"iso646.h",
				"limits.h",
				"locale.h",
				"math.h",
				"setjmp.h",
				"signal.h",
				"stdarg.h",
				"stdbool.h",
				"stddef.h",
				"stdint.h",
				"stdio.h",
				"stdlib.h",
				"string.h",
				"tgmath.h",
				"time.h",
				"wchar.h",
				"wctype.h",
				"sys/acct.h",
				"sys/debugreg.h",
				"sys/epoll.h",
				"sys/eventfd.h",
				"sys/fcntl.h",
				"sys/fsuid.h",
				"sys/gmon.h",
				"sys/gmon_out.h",
				"sys/inotify.h",
				"sys/io.h",
				"sys/kd.h",
				"sys/kdaemon.h",
				"sys/klog.h",
				"sys/mount.h",
				"sys/mtio.h",
				"sys/pci.h",
				"sys/perm.h",
				"sys/personality.h",
				"sys/prctl.h",
				"sys/profil.h",
				"sys/ptrace.h",
				"sys/quota.h",
				"sys/raw.h",
				"sys/reboot.h",
				"sys/reg.h",
				"sys/sem.h",
				"sys/sendfile.h",
				"sys/signal.h",
				"sys/signalfd.h",
				"sys/socketvar.h",
				"sys/soundcard.h",
				"sys/statvfs.h",
				"sys/swap.h",
				"sys/sysctl.h",
				"sys/sysinfo.h",
				"sys/termios.h",
				"sys/timerfd.h",
				"sys/ttychars.h",
				"sys/ultrasound.h",
				"sys/unistd.h",
				"sys/ustat.h",
				"sys/vfs.h",
				"sys/vlimit.h",
				"sys/vt.h",
				"sys/vtimes.h",
				"sys/xattr.h",
				"errno.h",
				"mathcalls.h",
				"net/ethernet.h",
				"net/if_arp.h",
				"net/if_ppp.h",
				"net/if_slip.h",
				"net/ppp_defs.h",
				"net/if.h",
				"net/if_packet.h",
				"net/if_shaper.h",
				"net/ppp-comp.h",
				"net/route.h",
				"netinet/ether.h",
				"netinet/if_fddi.h",
				"netinet/in.h	",
				"netinet/ip6.h",
				"netinet/udp.h",
				"netinet/icmp6.h",
				"netinet/if_tr.h",
				"netinet/in_systm.h",
				"netinet/ip_icmp.h",
				"netinet/if_ether.h",
				"netinet/igmp.h",
				"netinet/ip.h",
				"netinet/tcp.h",
				"rpc/types.h",
				"rpc/auth.h",
				"rpc/des_crypt.h",
				"rpc/pmap_prot.h",
				"rpc/rpc_msg.h",
				"rpc/xdr.h",
				"rpc/auth_des.h",
				"rpc/key_prot.h",
				"rpc/pmap_rmt.h",
				"rpc/svc.h",
				"rpc/auth_unix.h",
				"rpc/netdb.h",
				"rpc/rpc.h",
				"rpc/svc_auth.h",
				"rpc/clnt.h",
				"rpc/pmap_clnt.h",
				"rpc/rpc_des.h",
				"rpcsvc/bootparam.h",
				"rpcsvc/nis_callback.h",
				"rpcsvc/yp_prot.h",
				"rpcsvc/rstat.h",
				"rpcsvc/rusers.h",
				"rpcsvc/spray.h",
				"rpcsvc/ypupd.h",
				"rpcsvc/mount.h",
				"rpcsvc/nis.h",
				"protocols/routed.h",
				"protocols/rwhod.h",
				"protocols/talkd.h",
				"protocols/timed.h",
				"arpa/ftp.h",
				"arpa/inet.h",
				"arpa/nameser.h",
				"arpa/nameser_compat.h",
				"arpa/telnet.h",
				"arpa/tftp.h",
		};
		
		String args[] = {
				"-I"+headerFilePath+"/linux/include",
				"-I"+headerFilePath+"/linux/include/sys",
				"-I"+headerFilePath+"/linux/gcc/include",
				"-I"+headerFilePath+"/linux/x86_64-redhat-linux5E/include",
				"-I"+headerFilePath+"/linux/x86_64-redhat-linux5E/include/sys",
				"-D_X86_",
				"-D__STDC__",
				"-D_GNU_SOURCE",
				"-D__WORDSIZE=32",
				"-D__builtin_va_list=void *",
				"-D__DO_NOT_DEFINE_COMPILE",
				"-D_Complex",
				"-D__NO_STRING_INLINES",
				"-D__NO_LONG_DOUBLE_MATH",
				"-D__signed__",
				"-D__extension__=",
				"-D__GLIBC_HAVE_LONG_LONG=1",
				"-Daligned_u64=uint64_t",
		};
		
		parseHeaderFilesToGDT(outputDirectory, "generic_clib_new", "x86:LE:32:default", "gcc", filenames, args);
	}
}
